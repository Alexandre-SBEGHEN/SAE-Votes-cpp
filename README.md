## Infos importantes

Les votes à recréer :
- Majoritaire à 2 tours
- Alternatif
- Préférentiel

Nom du zip final : TD_1_E_6_POMET_REGUIG_SEHIL-FARADJI_SBEGHEN-MAGNIN.zip

A rendre avant le 26 novembre à midi

## Compiler un programme
- compiler le .cpp en exécutable
```cpp
g++ fichier.cpp -o fichier
```
- lancer l'exécutable
```cpp
./fichier < entree
```

## Choses à faire :

- Un rendu pdf expliquant quels systèmes de votes vous avez codé : 100%

- Le diaporama pour la présentation : 100%

- Les 3 codes pour les 3 systèmes de vote :
	- Vote majoritaire 2 tours : 100%
	- Vote préférentiel : 100%
	- Vote alternatif : 100%
- 2 jeux de tests pour chaque vote :
	- Premier : 100%
   	- Second : 100%
- Créer les projets **QTCreator** pour chaque vote
	- Vote majoritaire 2 tours : 100%
   	- Vote préférentiel : 100%
  	- Vote alternatif : 100%


## Liens importants : 

- https://en.wikipedia.org/wiki/Test_oracle
- https://ens.casali.me/category/sae/sae1-02/
- https://ametice.univ-amu.fr/course/view.php?id=145488
- https://fr.wikipedia.org/wiki/Syst%C3%A8me_%C3%A9lectoral

## Exemple vote préférentiel
### Borda classique
| 3 candidats (n=3) | Candidat 1 | Candidat 2 | Candidat 3 |
|-|-|-|-|
| Voies en pos 1 | 10 | 6 | 2 |
| Voies en pos 2 | 5 | 10 | 8 |
| Voies en pos 3 | 3 | 2 | 8 |
| Total points | 43 | 40 | 30 |

### Borda amélioré (avec les points au carré)

| 3 candidats (n=3) | Candidat 1 | Candidat 2 | Candidat 3 |
|-|-|-|-|
| Voies en pos 1 | 10 | 6 | 2 |
| Voies en pos 2 | 5 | 10 | 8 |
| Voies en pos 3 | 3 | 2 | 8 |
| Total points | 113 | 96 | 58 |
