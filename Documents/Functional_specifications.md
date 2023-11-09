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
  - [Laws and Regulations](#laws-and-regulations)
  - [Privacy](#privacy)
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
- Create original antagonist to represent original ghosts,
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

## Laws and Regulations

The legal landscape for a project like recreating Pac-Man in assembly x86 with DosBox[^4] involves considerations related to intellectual property[^5], copyright, and potentially other regulations. Here are some key aspects to be mindful of:

**Intellectual Property Rights:**
- Ensure that the recreation of Pac-Man does not infringe on the intellectual property rights of the original creators, Namco (now Bandai Namco Entertainment). Pac-Man is a copyrighted game, and any reproduction or adaptation must comply with copyright laws.

**Open-Source Licensing:**
- If the project involves the use of open-source[^6] tools, libraries, or code, it's essential to comply with the licensing terms associated with those resources. Different open-source licenses have varying requirements, and adherence to these terms is crucial for legal compliance.

**DosBox Licensing:**
- DosBox, being an open-source emulator, has its licensing terms. Make sure to review and comply with the DosBox license (GNU General Public License) when using the emulator in the project.

**Software Distribution Regulations:**
- If the Pac-Man project involves distribution of software, be aware of the regulations related to software distribution. This includes ensuring that users are aware of the terms of use and any licensing agreements associated with the software.

**Age and Content Ratings:**
- If the project is accessible to users of different age groups, consider compliance with age and content rating regulations. Clearly communicate the intended audience and ensure that the content is appropriate for the specified age group.

**PEGI (Pan European Game Information)**
- The Pac-Man project should consider obtaining a PEGI[^7] age rating to communicate the appropriate age group for the game. PEGI provides age classifications that help inform users and parents about the content suitability for different age ranges.

**Privacy Regulations:**
- If the project involves the collection or processing of user data, ensure compliance with data protection and privacy regulations. Clearly outline privacy policies, and if applicable, obtain user consent for data processing activities.

**Accessibility Standards:**
- Consider accessibility standards[^8] to ensure that the project is inclusive and complies with regulations related to accessibility for individuals with disabilities. This may include providing options for different control schemes or ensuring compatibility with assistive technologies.

**Consumer Protection Laws:**
- Adhere to consumer protection laws that may apply to software or game development projects. This includes providing accurate information about the project, offering customer support, and addressing any potential issues or complaints.

**Contractual Agreements:**
- If collaborating with others on the project, establish clear contractual agreements outlining the terms of collaboration, ownership of intellectual property, and any revenue-sharing arrangements.

**Local and International Laws:**
- Consider both local and international laws that may apply to the distribution and use of the Pac-Man project. This includes understanding the legal requirements in the jurisdictions where the project is made available.

## Privacy

Privacy considerations beyond legal requirements are crucial for building trust with users and promoting a positive user experience. Here are some additional privacy considerations for the Pac-Man project:

**Clear Privacy Policy:**
- Provide a clear and easily accessible privacy policy within the game or on the project's website. Clearly outline what data is collected, how it's used, and any third parties involved. Use simple language to make it understandable for users of all ages.

**Minimization of Data Collection:**
- Adopt a minimalistic approach to data collection. Only collect data that is essential for the functioning of the game and the user experience. Avoid unnecessary data points to reduce the impact on user privacy.

**Anonymous Gameplay Statistics:**
- If gathering gameplay statistics for improvements or analytics, consider aggregating and anonymizing[^9] the data. This allows for valuable insights without compromising individual user privacy.

**User Control over Data:**
- Empower users with control over their data. Offer options within the game settings that allow users to manage and customize privacy preferences, including the ability to opt out of certain data collection activities.

**Consent for Updates:**
- Obtain user consent before implementing significant updates or changes to the privacy policy. Keeping users informed and giving them the choice to accept or decline changes fosters a transparent and respectful relationship.

**Child-Friendly Privacy Features:**
- Implement features specifically designed for younger users, considering their unique privacy needs. For instance, incorporate parental controls, age-appropriate privacy settings, and child-friendly explanations of privacy concepts.

**Educational Pop-ups:**
- Integrate educational pop-ups or prompts within the game to inform users about privacy practices. Use engaging visuals and language that is accessible to a diverse audience, promoting awareness without causing user frustration.

**Regular Privacy Audits:**
- Conduct regular privacy audits to assess the data practices of the project. This includes reviewing data collection processes, storage security, and third-party integrations to identify and address potential privacy risks.

**Secure In-Game Communication:**
- If the Pac-Man project includes any form of in-game communication, prioritize the security of these communications. Implement encryption and moderation features to ensure a safe and private environment for users.

**User-Friendly Data Deletion:**
- Make it easy for users to delete their account and associated data. Provide a straightforward process within the game interface or website, and ensure that user data is promptly and securely deleted upon request.

**Transparent Notification Practices:**
-  Notify users in a transparent manner about any changes to the privacy policy or terms of service. Clearly communicate how these changes may impact their privacy and provide ample time for users to adjust settings or opt out if necessary.

## Cost analysis

- Project Duration: 
  - November 6, 2023, to December 22, 2023 (47 days).
- 24 project times of 3.5 hours each with a team of 6 people.
- 24 x 3.5 = 84.
- 84 hours are allocated to this project.

## Risk and assumptions

### Assumptions

**Technical Expertise:**
- The development team possesses the necessary technical expertise in assembly x86, DosBox, and game development to successfully recreate Pac-Man.

**Legal Compliance:**
- The project assumes that legal considerations, including copyright clearance for Pac-Man, will be successfully navigated to ensure compliance with intellectual property laws.

**User Engagement:**
- There is an assumption that users will engage positively with the recreated Pac-Man game, fostering community participation and potential future enhancements.

**Availability of Resources:**
- Resources, including human resources, software, and tools, will be available as needed throughout the project timeline.

**Budgetary Considerations:**
- The budget allocated for the project is sufficient to cover development, legal, marketing, and miscellaneous costs.

**Marketing Impact:**
- Marketing efforts, including promotional materials and advertising, will effectively reach the target audience and generate interest in the Pac-Man project.

**Timely Completion:**
- The project assumes that it will be completed within the specified timeline, avoiding significant delays or disruptions.

**Community Engagement:**
- There is an assumption that community engagement strategies, including a community manager, will contribute positively to the project's success.

**Quality Assurance:**
- The testing and quality assurance processes will effectively identify and address any bugs or issues, ensuring a polished and functional game.

### Risks

**Technical Challenges:**
- Unforeseen technical challenges in implementing assembly x86, DosBox integration, or other game development aspects may lead to delays or difficulties in achieving the desired functionality.

**Legal Hurdles:**
- Legal challenges related to securing copyright clearance for Pac-Man or other legal considerations may pose obstacles to the project's progression.

**User Adoption:**
- The risk exists that user adoption may not meet expectations, impacting the overall success of the project and its potential for community engagement.

**Resource Constraints:**
- Unexpected shortages or constraints in resources, including human resources or software tools, may impact the project's ability to meet deadlines or maintain quality standards.

**Budget Overruns:**
- Unforeseen expenses or budget overruns may strain financial resources, potentially affecting the project's scope or quality.

**Market Saturation:**
- The project faces the risk of being overshadowed by other gaming releases or failing to stand out in a market saturated with gaming options.

**Community Management Challenges:**
- Challenges in effectively managing the community, addressing concerns, and fostering positive engagement may lead to a less favorable reception of the project.

**Unforeseen Legal Changes:**
- Changes in intellectual property or copyright laws during the project's development may introduce unforeseen legal complications.

**Unpredictable Technical Issues:**
- Unpredictable technical issues, such as compatibility problems on different systems or devices, may arise during the testing phase.

**Market Response:**
- The market response may differ from expectations, affecting the project's reception and potentially requiring adjustments to marketing strategies.

## Success Criteria

The project will be considered as successful if all of these criterias have been met:

- The game display every element without any kind of stuttering,
- The player can control the character without latency between the player action and game's reaction,
- The player can progress amongst levels the same way as the original game,
- The game does not return errors on launch,
- The game does not crashes,
- The player can loose if conditions are met.

## Team Members

|Name|Photo|E-mail|
|-|-|-|
|Clémentine Curel|<img src="" style="height:100px">|clementine.curel@algosup.com|
|Laurent Bouquin|<img src="" style="height:100px">|laurent.bouquin@algosup.com|
|Aurélien Fernandez|<img src="" style="height:100px">|aurelien.fernandez@algosup.com|
|Mathias Gagnepain|<img src="" style="height:100px">|mathias.gagnepain@algosup.com|
|Gaël Malvar|<img src="" style="height:100px">|gael.malvar@algosup.com|
|Paul Nowak|<img src="" style="height:100px">|paul.nowak@algosup.com|

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

