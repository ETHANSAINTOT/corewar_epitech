# Corewar

## 🧠 Présentation

**Corewar** est un projet de simulation de bataille entre programmes en langage assembleur, se déroulant dans une **machine virtuelle** que vous devez coder en C.

Chaque programme appelé **champion** cherche à être le **dernier en vie** en exécutant régulièrement une instruction `live`, tout en effectuant des actions offensives ou défensives.

Le jeu s'inspire du célèbre jeu **Core War**, où des programmes en **Redcode** s'affrontent dans une mémoire partagée.

---

## ⚙️ Compilation

Le binaire principal s'appelle `corewar`.  
Le projet se compile avec un **Makefile** contenant les règles `all`, `clean`, `fclean` et `re`.

```bash
make        # Compile le programme
make clean  # Supprime les fichiers objets
make fclean # Supprime les binaires et les objets
make re     # Recompile depuis zéro
```

> ⚠️ **Il est fortement recommandé d’utiliser un système Linux** avec les outils suivants installés :
> - `make`
> - `gcc`
> - `libc` (standard C library)

---

## 🕹️ Fonctionnement général

Le projet est divisé en **trois parties** :

### 1. Les Champions (déjà fournis)

Ce sont des fichiers `.s` écrits dans un langage assembleur spécifique.  
Ils contiennent des instructions permettant à chaque programme de se défendre, d'attaquer ou de signaler sa survie via `live`.

---

### 2. L'Assembleur (déjà développé)

Ce composant transforme les fichiers `.s` en fichiers `.cor`, lisibles par la machine virtuelle.  
Il traduit chaque instruction assembleur en langage machine spécifique à Corewar.

---

### 3. La Machine Virtuelle (votre travail)

C’est **le cœur du projet**. Elle :

- Charge les champions en mémoire.
- Exécute leurs instructions dans un cycle de jeu simulant le parallélisme.
- Surveille les cycles de vie (`CYCLE_TO_DIE`), la validité des `live`, et déclare un **vainqueur**.

---

## 🔧 Options de la VM

```bash
./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
```

- `-dump nbr_cycle` : Affiche l’état de la mémoire après `nbr_cycle` cycles.
- `-n prog_number` : Définit le numéro du champion (sinon automatique).
- `-a load_address` : Adresse mémoire d’injection du champion (sinon réparti automatiquement).

---

## 🧾 Exemple d’utilisation

```bash
./corewar -dump 500 -n 1 -a 0x100 champion1.cor -n 2 -a 0x300 champion2.cor
```

---

## 🧱 Fonctionnement interne

### Ressources utilisées pour chaque programme :

- **REG_NUMBER** registres de **REG_SIZE** octets
- Un **compteur de programme (PC)** pointant sur la prochaine instruction
- Un **drapeau carry**, actif si la dernière opération renvoie 0

---

### Liste des instructions supportées

Quelques exemples :

| Instruction | Code Hex | Description |
|------------|----------|-------------|
| `live`     | `0x01`   | Signale que le joueur est en vie |
| `ld`       | `0x02`   | Charge une valeur dans un registre |
| `st`       | `0x03`   | Stocke une valeur d’un registre en mémoire |
| `add`      | `0x04`   | Additionne deux registres |
| `zjmp`     | `0x09`   | Saut conditionnel |
| `fork`     | `0x0c`   | Crée un nouveau processus |
| `aff`      | `0x10`   | Affiche un caractère depuis un registre |

> La liste complète est disponible dans `op.h` et `op.c`.

---

## 🧪 Résultats attendus

Durant l’exécution :

- Lorsqu’un joueur exécute `live`, le message suivant doit s’afficher :

```
The player 1("champion_name") is alive.
```

- Lorsque le jeu se termine, la sortie attendue est :

```
The player 2("champion_name") has won.
```

---

## 🖥️ Bonus potentiels

- Interface graphique pour suivre les déplacements en mémoire
- Mode pas-à-pas
- Système de logs détaillés
- Système de debug

---

## 📜 Remarques

- Le projet respecte les contraintes de **codage strictes** (norme Epitech).
- Aucun environnement graphique n’est requis pour faire fonctionner la machine virtuelle.
- La gestion des erreurs doit afficher les messages sur **stderr** et quitter avec le code **84**.

---

## 📚 Références utiles

- Le jeu **Core War** (1984) par A.K. Dewdney
- Langage **Redcode**
- Wikipedia : https://en.wikipedia.org/wiki/Core_War

---

## 📢 Clause pédagogique

> Ce projet a été réalisé dans un **cadre pédagogique** dans le cadre de l’école EPITECH.  
Il ne peut en aucun cas être utilisé à des fins commerciales ou être présenté publiquement sans mention explicite de son origine académique.

---

## 🏁 Bonne guerre, champions ! ⚔️
