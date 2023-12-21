# User Manual
---


## Installation on Linux & MacOS

### Prerequisites

- [DosBox](https://www.dosbox.com/download.php?main=1) (lastest version)
- [NASM](https://www.nasm.us/pub/nasm/releasebuilds/2.15.05/) (lastest version)

### getting the files

- Go to the [project](https://www.github.com/algosup/2023-2024-project-2-x86-retrogaming-team-2/tags).
- Select the lastest version
- Download the ( tar.gz ) file.
- Extract the file in the directory of your choice.
- Open DosBOX and run the following commands in the terminal:

```bash
mount c: /path/to/your/project
```

```bash
c:
```

```bash
main
```

[Save some time](#save-some-time)

## Installation on Widows 7+

### Prerequisites

- [DosBox](https://www.dosbox.com/download.php?main=1) (lastest version)
- [NASM](https://www.nasm.us/pub/nasm/releasebuilds/2.15.05/) (lastest version)

### getting the files

- Go to the [project](https://www.github.com/algosup/2023-2024-project-2-x86-retrogaming-team-2/tags). 
- Select the lastest version 
- Download the zip file.
- Extract the file in the directory of your choice.
- Open DosBOX and run the following commands in the terminal:

```bash
mount c: /path/to/your/project
```

```bash
c:
```

```bash
main
```

[Save some time](#save-some-time)


### Installation on Windows XP or older

- Go to the [project](https://www.github.com/algosup/2023-2024-project-2-x86-retrogaming-team-2/tags).
- Select the lastest version
- Download the "main.com" file.
- Run the file in the directory of your choice.



## Save some time

*! Only works for Linux, MacOS & Windows !*

- Find the DosBOX configuration file ( e.g. "dosbox-0.74-3.conf" ) and open it.
- Go to the end of the file and add the following lines:

```bash
mount c: /path/to/your/project
```

```bash
c:
```

- When you open DosBOX, you will be directly in the project directory.
- type "main" to start the game.