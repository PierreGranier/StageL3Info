#  [Site du projet Logique de Hoare](https://PierreGranier.github.io/StageL3Info)
===============
# Projet de stage L3 Info par [@PierreGranier](https://github.com/PierreGranier) et  [@ThibautRoperch](https://github.com/ThibautRoperch)

Vérificateur de preuves de programme en logique de Hoare

## Fonctionnalités du projet !

* Définir le format du fichier contenant une preuve
* Vérificateur de preuve
    * Système à construire avec Lex et Yacc (.lex et .y, versions Flex et GNU Bison)
    * Définir le langage d'une preuve d'après le format d'un fichier
    * Vérifier la syntaxe des règles de Hoare d'une preuve
    * Vérifier la sémantique des prédicats (pré et post conditions) d'une preuve
* Assistant de création de preuve
    * Interface graphique (IDE) à construire avec QT
    * Générer un fichier contenant la preuve en respectant le format défini

## Format d'une preuve

### Règles de Hoare

Les différentes règles de Hoare ([Wiki : Hoare](https://fr.wikipedia.org/wiki/Logique_de_Hoare "Wiki Hoare")) :
* AFF : Affectation  
![ADD](https://upload.wikimedia.org/math/0/b/9/0b9a2415175302dce994af21a9218367.png "ADD")
* SEQ : Composition (ou séquence)  
![SEQ](https://upload.wikimedia.org/math/a/6/f/a6f77b176903b2ee21016352ce1094b7.png "SEQ")
* COND : Conditionnelle  
![COND](https://upload.wikimedia.org/math/e/e/4/ee4f74d64cb71775ea181039c1634ac6.png "COND")
* CONSEQ : Consequence (ou affaiblissement)  
![CONSEQ](https://upload.wikimedia.org/math/e/7/4/e74a5e88893d68a24aa51b4f16f711f8.png "CONSEQ")
* WHILE : Itération  
![WHILE](https://upload.wikimedia.org/math/4/7/3/47393cfe477eaf8846db242ee9c818c5.png "WHILE")
* WHILET : Correction totale  
![WHILET](https://upload.wikimedia.org/math/3/a/5/3a559d4e19483b416de5a6fa94439d66.png "WHILET")

### Construction d'une preuve (dans un IDE)

* Comme dans le [cours de Courtieu (2008)](http://cedric.cnam.fr/~courtiep/downloads/hoare.pdf "Outils de preuve et vérification - Courtieu, 2008")
* Construction de la preuve de bas en haut
* Les prémisses sont en haut de la règle et la conclusion en bas

triplet1 ... tripletn  
      triplet

**{** précondition **}** variable **:=** valeur **{** postcondition **}** ... **{** précondition **}** variable **:=** valeur **{** postcondition **}**  
Nom de la règle ... Nom de la règle  
**{** précondition **}** variable **:=** valeur **{** postcondition **}**

### Génération d'une preuve (dans un fichier)

* Sur une seule ligne
* Les noms de règles utilisés comme des axiomes (ou fonctions)
* Lecture de la preuve de bas en haut

Nom de la règle(**{** précondition **}** variable **:=** valeur **{** postcondition **}**, Nom de la règle( etc... ))  
Le premier paramètre d'une règle étant la conclusion et les suivants les prémisses

## Vérificateur de preuve

### Langage

Tokens déjà présents dans les preuves :
* `AFF` : une règle de Hoare d’arité 1 (ne contient qu'une conclusion, pas de prémisse)
* `SEQ/COND/CONSEQ/WHILE/WHILET` : les règles de Hoare d'arité 2 (une conclusion puis une prémisse)

Tokens à définir :
* `ACCOLADE_OUVRANTE` et `ACCOLADE_FERMANTE` respectivement **{** et **}** : les caractères encadrant un prédicat
* `AFFECTATION` **:=** : le caractère d'affectation d'une valeur à une variable d'un programme
* `POINTVIRGULE` **;** : le caractère séparant deux instructions d'un programme

Principales règles à définir :
* La règle `Regle` est composée au mois d'un token correspondant au nom d'une règle de Hoare (plus de détails plus loin)
* La règle `Triplet` est composée d'une règle `Prédicat`, `Programme` et `Prédicat`
* La règle `Prédicat` est composée de la règle `Conditions` entre les caractères **{** et **}**
* La règle `Conditions` est un ensemble de règles `Condition` séparées par le caractère **;**
* La règle `Condition` est composé d'une expression, d'un symbole de comparaison et d'une autre expression
* La règle `Programme` est composée de règles `Instruction`
* La règle `Instruction` est composée d'une variable, du symbole **:=** et d'une expression

### Exemple

`SEQ {...}a:=0;b:=0{...} AFF {...}a:=0{...} AFF {...}b:=0{...}`
Note : les termes "conclusion" et "premisse" d'une règle de Hoare sont implicites : une conclusion est composée d'un triplet, et une premisse est composée d'une ou plusieurs règles de Hoare.

### Terminaison des règles de Hoare

La règle `Regle` liste les cas des règles de Hoare à vérifier :
* `AFF Triplet`
    * Chaque prédicat du triplet doit être juste sémantiquement
    * Le triplet doit être conforme syntaxiquement à la règle de Hoare `AFF`
* `AFF Triplet AFF Triplet`
    * *Mêmes choses que précédement*
    * La postcondition (deuxième prédicat) du premier triplet doit être égale à la précondition (premier prédicat) du second triplet
* `SEQ Triplet AFF Triplet AFF Triplet`
    * *Mêmes choses que précédemment*
    * La concaténation du programme des deux derniers triplets avec un **;** doivent être syntaxiquement équivalents au programme du premier triplet
* *...*

## Assistant de création de preuve

*A étudier*
*En Qt4 ou 5 ?*

## Liens utiles

* [Markdown](https://fr.wikipedia.org/wiki/Markdown "Wiki Markdown")
* [Wiki : Hoare](https://fr.wikipedia.org/wiki/Logique_de_Hoare "Wiki Hoare")
* [cours de Courtieu (2008)](http://cedric.cnam.fr/~courtiep/downloads/hoare.pdf "Outils de preuve et vérification - Courtieu, 2008")




        											 **
        											 /\
        										    /**\
        										   /*/\*\
        										  /*/**\*\
        										 /*/*/\*\*\
        										/*/*/**\*\*\
        									   /*/*/*/\*\*\*\
        									  /*/*/*/**\*\*\*\
        									 /*/*/*/*/\*\*\*\*\
        									/*/*/*/*/**\*\*\*\*\
        								   /*/*/*/*/*/\*\*\*\*\*\
        			      				  /*/*/*/*/*/**\*\*\*\*\*\
        								 /*/*/*/*/*/*/\*\*\*\*\*\*\
