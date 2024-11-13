
# Colorfull Driver 

Um driver simples para MINIX que muda dinamicamente as cores do terminal.

>Ainda em fase de teste

## Descrição

Este projeto implementa um driver de caracteres para MINIX que gera cores aleatórias para o terminal. O driver utiliza sequências ANSI para manipular as cores do terminal.

>A fazer: Adicionar forma de ativar drive r pelo teclado 

## Compilação e Instalação

Grande parte da instalação é parecida com o tuturial da wiki do MINIX
(Programming Device Drivers in Minix)[https://wiki.minix3.org/doku.php?id=developersguide:driverprogramming]

Navegue até a pasta dos drivers na fonte do MINIX

```bash
cd /usr/src/minix/drivers/examples
```

Clone o repositorio 
```bash
git -c http.sslVerify=false clone https://github.com/MaikeRob/colorfull_minix.git
cd colorfull_minix
```

Compile o driver
```bash
make
make install
```

Crie o arquivo o driver na pasta /dev
```bash
mknod /dev/colorfull c 17 0
```

Configure e inicie o driver
```bash
minix-service up /service/colorfull -dev /dev/colorfull
```

Agora vc já pode testar se está funcionando chamando o driver com um cat
```bash
cat /dev/colorfull
```

## Detalhes sobre os arquivos

O projeto é composto pelos seguintes arquivos:

colorfull.c

 - Implementação principal do driver


colors.c

 - Gerenciamento das cores ANSI 


colors.h

 - Definições das sequências de cores


utils.c

 - Funções utilitárias (Funções de aleatoriedade)


utils.h

 - Cabeçalhos das funções utilitárias


## Licença

Este projeto é parte de um trabalho acadêmico desenvolvido na disciplina de Sistemas Operacionais.
