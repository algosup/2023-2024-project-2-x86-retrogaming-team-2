# Functional Specifications


<details>
<summary>Table of content</summary>

- [Functional Specifications](#functional-specifications)
  - [Overview](#overview)
    - [What is Pac-Man](#what-is-pac-man)
    - [How To play](#how-to-play)
  - [Project Scopes](#project-scopes)
  - [Stakeholders](#stakeholders)
  - [Personas](#personas)
  - [Use cases](#use-cases)
    - [Thibaud, 8 years old:](#thibaud-8-years-old)
    - [Alice, 17 years old, High school student:](#alice-17-years-old-high-school-student)
    - [Claire, 27 years old, Developer:](#claire-27-years-old-developer)
    - [Jacques, 65 years old:](#jacques-65-years-old)
    - [Titouan, 35 years old, Gaming Enthusiast:](#titouan-35-years-old-gaming-enthusiast)
  - [Out of Scope](#out-of-scope)
  - [Non-functional requirements](#non-functional-requirements)
  - [Laws and regulations](#laws-and-regulations)
  - [Cost analysis](#cost-analysis)
  - [Risk and assumptions](#risk-and-assumptions)
    - [Assumptions](#assumptions)
    - [Risks](#risks)
  - [Success Criteria](#success-criteria)
  - [Team Members](#team-members)
  - [Glossary](#glossary)

</details>

## Overview

The goal of the project is to recreate the famous game "Pac-Man" with our own style using Assembly [^1] code and limiting the computer performance with the computing power of a computer of the 80s.

### What is Pac-Man

Pac-Man is a video game published in 1980 by the company Banday Namco. The game was playable on arcade. 

It consist on a yellow, round shaped character named "Pac-Man" eating "Pac-dots" on a 2D map.

The antagonists are little ghosts, four of them can be seen in the game. Each ghost has a name related to it's color except for the orange one.

<img src="./Images/Characters.jpg" width="300">
  
### How To play

The player, by controlling Pac-Man, has to eat every Pac-dots before one of the ghost catches him. If one of the ghost catches him, the player will lose a life and has to continue the level.

When the player loses all of his three lives, a screen displaying it's score will appear and the arcade will updates the top 10 high-score if needed.

The player can use either a joystick or arrows on the keyboard to play. Moving the joystick to one direction or pressing an arrow will move Pac-Man to this direction until hitting a wall.

<img src="./Images/Map.png" width="400">

 On the center of the leftmost and rightmost walls there is a path to teleport to the opposite side of the map, this path is commonly named "Tunnel".

 On each corners you can see bigger Pac-dots, they are called "Power pellets", when eating them, ghosts turns blue and will avoid Pac-Man, but if the player catches one of them, he will gain bonus points and the ghost will return in the center of the map to return to life and restart the chase.

 If the player achieve to get 10 thousand points, he will get an additional life, it happens for each multiple of 10 thousand.

## Project Scopes

Our project possess multiple scopes, we decided to make a list of the main features, which are:

- Create and display a map,
- Create and use an original character the player can use,
- Create original antagonists to represent original ghosts,
- Create the controller,
- Create collision[^2] boxes,
- Create lives system and death event,
- Enable the ability to eat dots,
- Enable the ability to use "Power-pellets",
- Enable the ability to change levels when eating every dots and "Power-pellets",
- Display effect on ghosts when taking "Power-pellets", 
- Enable the ability to eat ghosts after taking "Power-pellets",
- Enable the ghosts' ability to revive when going back to the center of the map,
- Calculate and display player's score.

## Stakeholders

|Image|Name|
|-|-|
|<img src="./Images/ALGOSUP.png" style="height:50px">|ALGOSUP|
|-|Team 2|


## Personas

<img src="Images/Persona 1.png" style="height: 400px">

<img src="./Images/Persona 2.png" style="height: 400px">

<img src="./Images/Persona 3.png" style="height: 400px">

<img src="./Images/Persona 4.png" style="height: 400px">

<img src="./Images/Persona 5.png" style="height: 400px">

## Use cases

### Thibaud, 8 years old:

Thibaud excitedly sits in front of the computer, ready to play the recreated Pac-Man game. With simple controls and vibrant graphics, he navigates through the mazes, collecting pellets and avoiding ghosts. Thibaud giggles with delight as he completes each level, feeling a sense of accomplishment. The accessible gameplay and engaging visuals keep him entertained, making the Pac-Man project his new favorite game.

### Alice, 17 years old, High school student:

After a long day of classes, Alice decides to take a break and explore the Pac-Man project. Despite not being a regular gamer, she finds the user-friendly[^3] interface and simple controls easy to navigate. The nostalgic elements of the classic game bring back childhood memories. Alice enjoys a quick gaming session, appreciating the break from her academic routine and the opportunity to explore a different aspect of technology.

### Claire, 27 years old, Developer:

Claire, a developer with a busy schedule, decides to unwind by trying out the Pac-Man project. Although not directly involved in its development, she appreciates the clear project objectives and the collaborative environment. Claire explores the technical aspects with curiosity, recognizing the efforts put into recreating the classic game. The project becomes a source of both relaxation and a chance to appreciate game development from a user's perspective.

### Jacques, 65 years old:

Jacques, a nostalgic gamer, sits down to play the recreated Pac-Man on his computer. Guided by a user-friendly interface and simple controls, he navigates through the mazes, reminiscent of his past gaming experiences. Despite initial concerns about technology, Jacques finds the project accessible and comfortable. The nostalgic elements evoke fond memories, creating an enjoyable gaming session that bridges the gap between classic and modern gaming.

### Titouan, 35 years old, Gaming Enthusiast:

Scenario: Titouan, a gaming enthusiast with a versatile history of playing Pac-Man, eagerly explores the Pac-Man project. With a mix of nostalgia and curiosity, he appreciates the versatility in gameplay and the project's efforts to capture the essence of the classic game. Titouan engages with the community, sharing insights based on his gaming expertise. The project becomes a platform for him to not only enjoy a beloved classic but also contribute to the gaming community.


## Out of Scope

The project also have some out of scope objectives, there are as following:

- Playing music and sound in-game, we are focusing on having a playable game first, the sound effects are not a top priority for our team,
- Display a main menu at the start of the game and a Highest scores menu at the end of a game,
- Creating the equivalents of fruits, they only give bonus points and aren't a core part of the gameplay.

## Non-functional requirements

The project contains two non-functional requirements which are the following:

The game must react to player's action in less than a second, the player canno't be subject to input latency.

The game must be understandable for young players, it shouldn't require more than ten minutes to comprehend the gameplay.

The game should be playable on a x86 emulator.

## Laws and regulations

The legal landscape for a project like recreating Pac-Man in assembly x86 with DosBox[^4] involves considerations related to intellectual property[^5], copyright, and other regulations. Here are some key aspects we are mindful of:

**Software distribution regulations:**
- The game Pac-Man is under trademark. It means any reference or uses of its characters or the use of the source code by other companies can be declared as illegal and thus the owner of the trademark can pursue legal action against infringing company.

**Age and content ratings:**
- In adherence to age and content rating regulations, our project aligns with the PEGI 3 rating, signaling its suitability for users of all age groups. We prioritize transparency by clearly communicating the intended audience, ensuring that the content is specifically crafted to be appropriate for individuals aged three and above. This commitment extends to the design, themes, and any interactive elements within the game.<br>
By conforming to the PEGI 3 rating, we aim to provide a safe and enjoyable gaming experience for users of diverse age ranges. The clarity in age and content communication not only fulfills regulatory requirements but also assists users and parents in making informed decisions about the suitability of our game for their audience. 

**Privacy regulations:**
- By processing data such as the collect of player's experience by using the "score" we should ensure players are aware of this. Consent and awareness of our users must be mandatory in case of data collection. 

**Consumer protection laws:**
- In our game development project, we are committed to upholding consumer protection laws to ensure a positive and transparent user experience. Our game description provides accurate and detailed information about the gameplay and any features present in the game. We prominently display terms of service and privacy policies, outlining how user data is handled and protected.

**Minimization of data collection:**
- Our data, being limited to player's score and being locally stored, players can safely stay anonymous.

## Cost analysis

- Project Duration: 
  - November 6, 2023, to December 22, 2023 (47 days).
- 24 project times of 3.5 hours each with a team of 6 people.
- 24 x 3.5 = 84.
- 84 hours are allocated to this project.

## Risk and assumptions

### Assumptions

**Technical expertise:**
- The development team possesses the necessary technical expertise in assembly x86, DosBox, and game development to successfully recreate Pac-Man.

**Legal compliance:**
- The project assumes that legal considerations, including trademark clearance for Pac-Man, will be successfully navigated to ensure compliance with intellectual property laws.

**User engagement:**
- There is an assumption that users will engage positively with the recreated Pac-Man game, fostering community participation and potential future enhancements.

**Timely completion:**
- The project assumes that it will be completed within the specified timeline, avoiding significant delays or disruptions.

**Quality assurance:**
- The testing and quality assurance processes will effectively identify and address any bugs or issues, ensuring a polished and functional game.

### Risks

**Technical challenges:**
- Unforeseen technical challenges in implementing assembly x86, DosBox integration, or other game development aspects may lead to delays or difficulties in achieving the desired functionality.

**Legal hurdles:**
- Legal challenges related to securing copyright clearance for Pac-Man or other legal considerations may pose obstacles to the project's progression.

**Resource constraints:**
- Unexpected shortages or constraints in resources, including human resources or software tools, may impact the project's ability to meet deadlines or maintain quality standards.

**Unforeseen legal changes:**
- Changes in intellectual property or copyright laws during the project's development may introduce unforeseen legal complications.

**Unpredictable technical issues:**
- Unpredictable technical issues, such as compatibility problems on different systems or devices, may arise during the testing phase.

## Success Criteria

The project will be considered as successful if all of these criterias have been met:

- The game display every element without any kind of stuttering,
- The player can control the character without latency between the player action and game's reaction,
- The player can progress amongst levels the same way as the original game,
- The game does not return errors on launch,
- The game does not crashes,
- The player can loose if conditions are met.

## Team Members

|Name|Role|Photo|E-mail|
|-|-|-|-|
|Clémentine Curel|Senior software engineer|<img src="" style="height:100px">|clementine.curel@algosup.com|
|Laurent Bouquin|Project manager|<img src="" style="height:100px">|laurent.bouquin@algosup.com|
|Aurélien Fernandez|Program manager|<img src="" style="height:100px">|aurelien.fernandez@algosup.com|
|Mathias Gagnepain|Junior software engineer|<img src="" style="height:100px">|mathias.gagnepain@algosup.com|
|Gaël Malvar|Quality assurance|<img src="" style="height:100px">|gael.malvar@algosup.com|
|Paul Nowak|Tech lead|<img src="" style="height:100px">|paul.nowak@algosup.com|

## Glossary

[^1]: Assembly Code:
Low-level programming language specific to a computer architecture. Used in this project to create the Pac-Man game.

[^2]: Collision Boxes:
Virtual boxes used in game development to detect collisions between objects.

[^3]: User-Friendly:
Design and functionality that are easy for users to understand and navigate.

[^4]: DosBox :
An emulator that allows running old games on modern computers.

[^5]: Intellectual Property:
Legal rights that result from intellectual activity in industrial, scientific, literary, and artistic fields.

[^6]: Open-Source:
Software whose source code is available to the public, allowing users to modify and distribute it.

[^7]: PEGI (Pan European Game Information):
A European video game content rating system to inform consumers about the suitability of games for different age groups.

[^8]: Accessibility Standards:
Guidelines and standards to ensure that software and technology are accessible to individuals with disabilities.

[^9]: Anonymizing Data:
Removing personally identifiable information from data to protect user privacy.

