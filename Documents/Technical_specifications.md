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
    - [Other solutions](#other-solutions)
    - [Out of scope](#out-of-scopes)
  - [Gameplay](#gameplay)
    - [Game screen](#game-screen)
    - [Game rules](#game-rules)
    - [Game mechanics](#game-mechanics)
    - [Sprites gallery](#sprites-gallery)
    - [Demo](#demo)
  - [Technologies used](#technologies-used)
    - [Programming language](#programming-language)
    - [DOSBOX](#dosbox)
    - [Processus of installation](#processus-of-installation)
    - [Dependencies](#dependencies)
    - [Virtual Machine configuration](#virtual-machine-configuration)
    - [Problems encountered](#problems-encountered)
  - [Glossary](#glossary)

</details>

## Overview

### Short presentation
Pac-Man (originally named Puckman in english) is a 1980 arcade game developped by the japanese video game company called Bandai Namco Entertainment Inc.

First released in Japan, it became a massive success in the United States where more than 100 000 units were sold in 1 year.

In his game, Pacman must eat all the pac-dots present in a maze while he is chased by 4 ghosts. However, he can eat super-powered pellets where he gets temporarily the power to devour his enemies !

Today, the character became a cultural icon of the video game industry which the popularity has crossed the globe.

### Goal
Our goal is to recreate our own version of a Pac-Man game while using our own creative and technical choices.

However, we are required to use the Assembly programming language which include limited computer features. Furthermore, we have to use DOSBOX, an emulator recreating a MS-DOS environment.

## Technical requirements
The goal

### Proposed solution
AAA

### Decisions taken
During the planning phase of our game, several critical choices must have been done in order to avoid a catastrophic phase of development:

#### Key Handler
To anticipate the different kinds of player who are right-handed or left-handed, we have decided to allow different game controls, like arrow keys or other keyboard keys.

So, we plan to incorporate several variables that have several keyboard keys assigned to them (Ex: "Go UP" variable connected to Up Arrow key or W Key).

Furthermore, the key handler must detect the same scancode regardless if it's uppercase or lowercase.

### Other solutions

The plan of our maze was originally much bigger and would take most of the screen size. However, we expected to experiment graphics issues in case we have to reduce the scren size, and we also needed to include the score.

### Out of scope
First of all, we have decided to exclude the bonus fruits in our game due to time constraints. We believed that it was the less important feature to implement, and we would have replaced them with other kinds of food (Soda, etc...) if we had time.

Then, we didn't want to add sound and music in our game. Indeed, we prefered to focus on the functional requirements of our Pac-Man and ignore its sound aesthetics.

## Gameplay
The goal

### Game screen
AAA

### Game rules
AAA

### Game mechanics
AAA

### Sprites gallery
AAA

### Demo
Here's a (upcoming) demo of our game:

## Technologies used
The goal

### Programming language
AAA

### DOSBOX
AAA

### Processus of installation
AAA

### Dependencies
AAA

### Virtual Machine configuration
AAA

### Problems encountered
AAA

## Glossary
The goal