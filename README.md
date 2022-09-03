# Minishell


## Overview :

In order to execute a command in linux, we need a terminal and a program to compile. A terminal is a device for displaying characters on the screen(stdout), and getting characters from the keyboard, without a program to run those commands, a terminal is pointless. A shell is a program that reads from the terminal and executes the commands, it is like a interactive programming language, the user writes the command and the shell executes it.

The way the commands are processed :

<img width="703" alt="Screen Shot 2022-09-02 at 11 10 38 AM" src="https://user-images.githubusercontent.com/96797193/188117743-b0757415-b38c-42b3-bd39-0cf4d8e93f0a.png">

## Parsing :

lexer-tokenisation-envoi de tout end back-end(execution)
{
  Les séparations
  Les pipes
  Commande et arguments
  Les protections
  Les redirections <, >, >>
  Les variables d'environnement
}
## Execution :
{
  Les redirections
  builtins
  Exit et $?
  Liens pipes/signaux/processus
}
Redirection :

<img width="1073" alt="Screen Shot 2022-09-02 at 11 18 29 AM" src="https://user-images.githubusercontent.com/96797193/188118795-acb3d719-9eb6-4fa4-91ba-34d3795a2fec.png">

## Ressources :

<ul>
  <li>http://www-igm.univ-mlv.fr/~forax/ens/java-avance/cours/pdf/old/Generation%20de%20code%201.pdf</li>
  <li>https://miro.com/app/board/uXjVO3ccsYw=/</li>
  <li>https://en.wikipedia.org/wiki/Lexical_analysis</li>
 </ul>
