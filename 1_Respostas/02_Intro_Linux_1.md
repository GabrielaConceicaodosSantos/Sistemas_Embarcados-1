

1. Por que o Linux recebeu esse nome?

O nome vem direto do seu criador, Linus Torvalds. O nome é uma junção dos nomes Linus + MINIX. O MINIX foi um sistema operacional criado por Andrew Tanenmbaum para ensinar os fundamentos de sistemas operacionais para estudantes. Ficando um pouco frustrado com a pequena aplicação do SO, ele decidiu fazer o seu próprio SO baseado no MINIX e assim nasceu o linux.


2. O que são daemons?

Daemon é um software que fica executando sem o controle direto do usuário. Por convenção, para diferenciar de um processo de um software normal, o processo dos daemons terminam com a letra "d". Um daemon controle (inicia, reinicia, para e etc) um serviço provido pelo sistema.


3. O que é o shell?

O Shell (concha) é um programa que permite ao usuário iteragir com o sistema operacional através de comandos digitados do teclado. A sua função é ler a linha de comando, interpretar o significado, executar o comando e devolver o resultado pelas saídas. Existem vários tipos de Shell, sendo os mais comuns o sh (chamado Bourne shell), o bash (Bourne again shell), o csh (C shell), o Tcsh (Tenex C shell), o ksh (Korn shell) e o zsh (Zero shell). O Shell mais famoso no Linux é o Bash.


4. Por que é importante evitar executar o terminal como super-usuário?

Super-usuário ou Root (raiz) refere-se a um tipo de usuário com privilégios absolutos. Com o Root é possível ter controle total sobre o sistema (executar comandos absolutos e ter acesso a processos), o que pode ser muito interessante e também muito perigoso. Portanto o mais recomendado não é logar como Root, e sim utilizar comandos como **su** e **sudo**. O primeiro loga como Root e outr usuário em um terminal, podendo depois fazer logoff com o comando **exit**, o segundo apenas executar um comando em um terminal com privilégios de super usuário.   

5. Qual botão do teclado completa o que o usuário escreve no terminal, de acordo com o contexto?

**TAB**: TAB autocompleta a linha de um texto. Digamos que você deseja digitar cd ~/Dropbox/ `, você pode digitar somente `cd ~/Dr` e então apertar TAB para completar o comando. 

6. Quais botões do teclado apresentam instruções escritas anteriormente?

Apresente os respectivos comandos no terminal para:

 (a) Obter mais informações sobre um comando.

 (b) Apresentar uma lista com os arquivos dentro de uma pasta.

``` 
	$ ls
```

 (c) Apresentar o caminho completo da pasta.

 (d) Trocar de pasta.

 (e) Criar uma pasta.

``` 
	$ mkdir #nome_da_pasta
```

 (f) Apagar arquivos definitivamente.

 (g) Apagar pastas definitivamente.

 (h) Copiar arquivos.

 (i) Copiar pastas.

 (j) Mover arquivos.

 (k) Mover pastas.

 (l) Renomear pastas.

 (m) Apresentar o conteúdo de um arquivo.

 (n) Apresentar o tipo de um arquivo.

 (o) Limpar a tela do terminal.

 (p) Encontrar ocorrências de palavras-chave em um arquivo-texto.

 (q) Ordenar informações em um arquivo-texto.

 (r) Substituir ocorrências de palavras-chave em um arquivo-texto.

 (s) Conferir se dois arquivos são iguais.

 (t) Escrever algo na tela
