# Stage L3 Info

Vérificateur de preuves de programme en logique de Hoare

## Fonctionnalités du projet

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

### Construction d'une preuve (dans un IDE)

* Comme dans le cours de Courtieu
* Construction de la preuve de bas en haut

triplet1 ... tripletn  
      triplet

**{** précondition **}** variable **:=** valeur **{** postcondition **}** ... **{** précondition **}** variable **:=** valeur { postcondition **}**
Nom de la règle ... Nom de la règle  
**{** précondition **}** variable **:=** valeur **{** postcondition **}**

### Génération d'une preuve (dans un fichier)

* Sur une seule ligne
* Utilisant des axiomes
* Lecture de la preuve de bas en haut

Nom de la règle(**{** précondition **}** variable **:=** valeur **{** postcondition **}**, Nom de la règle( etc... ))

## Vérificateur de preuve

### Langage (axiomes)

AFF/SEQ/CONSEQ/WHILE/WHILET d’arité 2 : les règles de Hoare
PREMISSE d’arité 1 : la prémisse d’une règle
CONSEQUENCE d’arité n (0 à ∝) : la conséquence d’une règle

### Exemple

SEQ PREMISSE {...}a:=0;b:=0{...} CONSEQUENCE AFF PREMISSE {...}a:=0{...} CONSEQUENCE AFF PREMISSE {...}b:=0{...} CONSEQUENCE

### Terminaison des axiomes



## Assistant de création de preuve
