# Technical Specifications

<details>
<summary>Table of content</summary>

- [Technical Specifications](#technical-specifications)
  - [Overview](#overview)
    - [Short presentation](#short-presentation)
    - [Goal](#goal)
  - [Technical requirements](#technical-requirements)
    - [Proposed solution](#proposed-solution)
    - [Decisions taken](#decisions-taken)
      - [Key Handler](#key-handler)
      - [Screen Resolution](#screen-resolution)
    - [Other solutions](#other-solutions)
    - [Out of scope](#out-of-scopes)
  - [Gameplay](#gameplay)
    - [Game screen](#game-screen)
    - [Controls](#controls)
    - [Mechanics and rules](#mechanics-and-rules)
    - [Sprites gallery](#sprites-gallery)
      - [Hero](#hero)
      - [Ghosts](#ghosts)
      - [Others](#others)
    - [Demo](#demo)
  - [Technologies](#technologies)
    - [Programming language](#programming-language)
    - [x86 Microprocessor](#x86-microprocessor)
    - [Processus of installation](#processus-of-installation)
    - [Dependencies](#dependencies)
    - [Problems encountered](#problems-encountered)
  - [Tools used](#tools-used)
    - [DosBox](#dosbox)
    - [Gimp](#gimp)
  - [Glossary](#glossary)

</details>

## Overview

### Short presentation
Pac-Man (originally named Puckman in english) is a 1980 arcade game developped by the japanese video game company called Bandai Namco Entertainment Inc and designed by Toru Iwatani.

First released in Japan, it became a massive success in the United States where more than 100 000 units were sold in 1 year.

In his game, Pacman must eat all the pac-dots present in a maze while he is chased by 4 ghosts. However, he can eat super-powered pellets where he gets temporarily the power to devour his enemies !

Today, the character became a cultural icon of the video game industry which the popularity has crossed the globe.

### Goal
Our goal is to recreate our own version of a Pac-Man game while using our own creative and technical choices.

However, we are required to use the Assembly programming language which include limited computer features. Furthermore, we have to use DOSBOX, an emulator recreating a MS-DOS environment.

## Technical requirements
The goal

### Proposed solution
Our solution is a game named "Dev Track": it's a 1-player maze action game that is close to the original's game's aspect and gameplay. 

However, our version will propose a different map and different sprites for the characters involved. Furthermore, this game will be played on PC and ran on the DosBox virtual machine.

When making that game, we want to trigger to the player a feeling of challenge, because the game tends to be harder at each level, and a feeling of achievement after he managed to succeed.


### Decisions taken
During the planning phase of our game, several critical choices must have been done in order to avoid a catastrophic phase of development:

#### Key Handler
To anticipate the different kinds of player who are right-handed or left-handed, we have decided to allow different game controls, like arrow keys or other keyboard keys.

So, we plan to incorporate several variables that have several keyboard keys assigned to them (Ex: "Go UP" variable connected to Up Arrow key or W Key).

Furthermore, the key handler must detect the same scancode regardless if it's uppercase or lowercase.

#### Screen Resolution
Originally, we planned to have a screen resolution of 640*800 pixels, for a total of 307 000 pixels. The problem is that our game is limited to a 16-bit game can only support up to 65 536 pixels, which isn't enough to provide such a screen quality.

So, we had decided to opt for a 320*200 pixels resolution, with a total of 64 000 pixels.

In addition, we had to reduce the sprites' size from 16*16 to 8*8 pixels.



### Other solutions

The plan of our maze was originally much bigger and would take most of the screen size. However, we expected to experiment graphics issues in case we have to reduce the screen resolution, and we also needed to include the score.

Here are some concepts of maze that were considered during the project's development:

CONCEPTS


### Out of scope
First of all, we have decided to exclude the bonus fruits in our game due to time constraints. We believed that it was the less important feature to implement, and we would have replaced them with other kinds of food (Soda, etc...) if we had time.

Then, we didn't want to add sound and music in our game. Indeed, we prefered to focus on the functional requirements of our Pac-Man and ignore its sound aesthetics.

## Gameplay
The goal

### Game screen
This is how the game screen looks like in our game:

<img src="./Images/Map_New.png" width="500">


Dev Track's maze occupies most of the entire screen, while upper-top band hows a black area containing the actual score, the high score and the number of Pac-Man's remaining lives.

To display the maze, we use the "SCREEN MODE" in order to display each walls, setting up the tunnels where the characters are allowed to roam in, and displaying external content.





### Controls
For controling our hungry red ball, we use the keyboard touches to move the character from a x-z plane fixed camera movement.

Indeed, we can either used the arrows keys to move our hero, or for the left-handed players, we can use the WASD keys.

Moving through the maze will be the only thing the player could do with our character, as the latter will automatically interact with the other game systems (enemies, pac-dots..;) when entering in collision with them.

### Mechanics and rules
AAA

FPS

Character speed

Character hitboxes

Ghost speed and hitboxes

Ghost speed increase when we eat a certain number of pellets

events

The number of power-pellet eaten



Each of the ghosts possesses a different AI when following Ranky, but we have chosen to not create our own AI for time constraints. So, we decided to retrieve the original game's respective AIs for programming the ghosts by adapting them to our game.

In this game, the ghost's velocity will only increase depending on the level played.



Both Ranky and the ghosts have different states depending on the situation, so here's a state diagram to illustrate them:

STATE DIAGRAM



### Sprites gallery

#### Hero

The hero's sprite is based on the ALGOSUP's logo.

|         Sprite         |                  Name                   |  Size  |               Details              |
| :------------------: | :------------------------------------------: | :------------------: | :------------------: |  
| <img src="Images/Opened-Pac.png" style="height: 200px" width= 200px>|   Ranky-opened mouth    |  16*16  | Fixed animation when Ranky is in his idle animation, but also used alternatively during moving animation. |
| <img src="Images/Closed-Pac.png" style="height: 200px" width= 200px> |   Ranky-closed mouth    |  16*16  | Used alternatively during moving animation. |    

#### Ghosts
We created new sprites for enemies, with different designs and different names.

#### Others
AAA


### Demo
Here's a (upcoming) demo of our game:




## Technologies 
The goal

### Programming language
The Algosup School imposed us the use of the Assembly language, more particularly x86 Assembly.

<img src="./Images/ASMLogo.png" width="300">

Assembly is the lowest language available of software programming that is the closest of the machine language. Indeed, it allow us to access to all of what is possible to do with our computer, as it's important to understand how a machine works for the programming complexity.

Futhermore, the language requires less memory and execution time, and will be more suitable for hardware-specific complex tasks.

Now, our team is stick to use the x86 Assembly version due to DosBox being a x86 emulator.



### x86 Microprocessor REGISTERS ARE ENOUGH

To simulate the technical limitations of MS-DOS, Franck told us to use the 16-bit microprocessor Intel 8086 for making our game which can also work on a modern machine. It's a 40-pin DIL-shaped integrated circuit as shown in the following figure:

https://www.technologuepro.com/microprocesseur/chap2_microprocesseur_fichiers/Image0.jpg


Mostly used for desktop computers and launched in 1978, this processor has a clock speed from 5 to 10 MHz, a cache memory of 64 KB and a maximum memory capacity of 1 MB. 

Here's the intern architecture of the device:

https://www.technologuepro.com/microprocesseur/chap2_microprocesseur_fichiers/Image1.jpg

As you can see, there are 2 intern units:
  - the Bus Interfaccing Unit (BIU) , which retrieves and stores the data to be processed, and establish transmissions with the system buses.
  - the Execution Unit (EU), that executes the instructions which are transmitted by the BIU.

First of all, when the execution of an instruction is completed, the Execution Unit remains idle for a short time, while the Bus Interfacing Unit fetches the next instruction. However, a 6-byte prefetch queue for pipeline processing has been introduced in the 8086/8088.

Then, while the EU executes the information transmitted to it, the next instruction is loaded into the BIU. The instructions that follow are placed in the queue.

After the EU has finished processing an instruction,  the BIU instantly transmits the next instruction to it, and loads the third instruction in order to transmit it to the continuously active EU. 


Within the EU, 16-bit registers can be used in all arithmetic and logical operations that the programmer inserts into the code.

These 8 registers are separated into 2 groups:

  - 4 data 16-bit registers that can be separated into 2 8-bit registers.

  <img src="./Images/DataRegisters.jpg" width="500">

https://www.technologuepro.com/microprocesseur/chap2_microprocesseur_fichiers/Image2.jpg

  - 4 16-bit registers used for pointers and indexes, more specifically adapted to the processing of elements in memory. They generally have increment and decrement properties.

https://www.technologuepro.com/microprocesseur/chap2_microprocesseur_fichiers/Image3.jpg

<img src="./Images/DataRegisters.jpg" width="500">



### Processus of installation
AAA

### Dependencies
AAA

### Problems encountered
AAA


## Tools Used 
The goal

### DosBox
We were required to use the virtual machine DosBox: it's an emulator recreating the MS-DOS environment that can run many classic MS-DOS games as long as they aren't modified.

DosBox logo

First, we download and install the emulator's latest version: DosBox 0.74-3.

However, it needs some location to emulate a virtual Hard Drive while the computer's hard drive is much larger than the ones used when MS-DOS was commercially available. When we open the emulator, we are welcomed with a terminal that reads Z:\>. Though, users cannot write data here as it only exists for DosBox purposes.

Dosbox prompt

To remedy the issue, we have to create a realistic and safe path environment in order to run our DOS software. For that, we should define a path somewhere in our hard disk that will be treated like a virtual hard disk.

Then, we need to mount a drive: mount is a command inside DosBox that can connect physical folders and drives to virtual drives. For that, we select a folder (a sub-folder of the target folder is recommanded) as a drive where the DOS files will be stored and have DOSBox fool its games/applications into thinking that is the C: drive.

Once we found our target path, we enter this command:

  - mount c "Target Path"

We click enter and the drive C will be mounted as a local directory.

Photo dosbox path

Now that the command prompt will be set up, we will be able to compile and run .asm files.





### Gimp
For creating the concepts of our maze and sprites, we used Gimp as a designing tool.

<img src="./Images/gimpLogo.png" width="300">

It's an high quality framework for scripted image manipulation that provides us sophisticated tools to create, modify and enhances images.


## Glossary
The goal

maze game

microprocessor

virtual machine

drive

sprite

prefetch queue

pipeline processing