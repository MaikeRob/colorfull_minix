#include <minix/drivers.h>
#include <minix/chardriver.h>
#include <stdio.h>
#include <stdlib.h>
#include <minix/ds.h>
#include "colors.h"
 
/*
 * Function prototypes for the colorfull driver.
 */
static int colorfull_open(devminor_t minor, int access, endpoint_t 
user_endpt);
static int colorfull_close(devminor_t minor);
static ssize_t colorfull_read(devminor_t minor, u64_t position, 
endpoint_t 
endpt,
    cp_grant_id_t grant, size_t size, int flags, cdev_id_t id);
 
/* SEF functions and variables. */
static void sef_local_startup(void);
static int sef_cb_init(int type, sef_init_info_t *info);
static int sef_cb_lu_state_save(int, int);
static int lu_state_restore(void);
 
/* Entry points to the colorfull driver. */
static struct chardriver colorfull_tab =
{
    .cdr_open	= colorfull_open,
    .cdr_close	= colorfull_close,
    .cdr_read	= colorfull_read,
};
 
/** State variable to count the number of times the device has been 
opened.
 * Note that this is not the regular type of open counter: it never 
decreases.
 */
static int open_counter;
 
static int colorfull_open(devminor_t UNUSED(minor), int UNUSED(access),
    endpoint_t UNUSED(user_endpt))
{
    printf("colorfull_open(). Called %d time(s).\n", ++open_counter);
    return OK;
}
 
static int colorfull_close(devminor_t UNUSED(minor))
{
    printf("colorfull_close()\n");
    return OK;
}
 
static ssize_t colorfull_read(devminor_t UNUSED(minor), u64_t position,
    endpoint_t endpt, cp_grant_id_t grant, size_t size, int 
UNUSED(flags),
    cdev_id_t UNUSED(id))
{
    u64_t dev_size;
    char *ptr;
    int ret;
    char *buf = (char *)native_get_radom_color();
 
    printf("colorfull_read()\n");
 
    /* This is the total size of our device. */
    dev_size = (u64_t) strlen(buf);
 
    /* Check for EOF, and possibly limit the read size. */
    if (position >= dev_size) return 0;		/* EOF */
    if (position + size > dev_size)
        size = (size_t)(dev_size - position);	/* limit size */
 
    /* Copy the requested part to the caller. */
    ptr = buf + (size_t)position;
    if ((ret = sys_safecopyto(endpt, grant, 0, (vir_bytes) ptr, size)) 
!= OK)
        return ret;
 
    /* Return the number of bytes read. */
    return size;
}
 
static int sef_cb_lu_state_save(int UNUSED(state), int UNUSED(flags)) {
/* Save the state. */
    ds_publish_u32("open_counter", open_counter, DSF_OVERWRITE);
 
    return OK;
}
 
static int lu_state_restore() {
/* Restore the state. */
    u32_t value;
 
    ds_retrieve_u32("open_counter", &value);
    ds_delete_u32("open_counter");
    open_counter = (int) value;
 
    return OK;
}
 
static void sef_local_startup()
{
    /*
     * Register init callbacks. Use the same function for all event 
types
     */
    sef_setcb_init_fresh(sef_cb_init);
    sef_setcb_init_lu(sef_cb_init);
    sef_setcb_init_restart(sef_cb_init);
 
    /*
     * Register live update callbacks.
     */
    sef_setcb_lu_state_save(sef_cb_lu_state_save);
 
    /* Let SEF perform startup. */
    sef_startup();
}
 
static int sef_cb_init(int type, sef_init_info_t *UNUSED(info))
{
/* Initialize the colorfull driver. */
    int do_announce_driver = TRUE;
 
    open_counter = 0;
    switch(type) {
        case SEF_INIT_FRESH:
            printf("Starting driver!");
        break;
 
        case SEF_INIT_LU:
            /* Restore the state. */
            lu_state_restore();
            do_announce_driver = FALSE;
 
            printf("Hey, I'm a new version!\n");
        break;
 
        case SEF_INIT_RESTART:
            printf("Hey, I've just been restarted!\n");
        break;
    }
 
    /* Announce we are up when necessary. */
    if (do_announce_driver) {
        chardriver_announce();
    }
 
    /* Initialization completed successfully. */
    return OK;
}
 
int main(void)
{
    /*
     * Perform initialization.
     */
    sef_local_startup();
 
    /*
     * Run the main loop.
     */
    chardriver_task(&colorfull_tab);
    return OK;
}
