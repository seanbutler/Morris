# Morris Programming Language

Morris is a programming language hand crafted for making games quickly and easily. 
Morris has a focus on ease of gameplay programming.

The infrastructure parts of the game: graphics, physics, window, input, sound, fonts, networking, etc. are all integrated and ready to go because of the wonderful SFML.

Morris programs look very familiar to anyone who has used c js c++ rust or swift. Right now, Morris programs look like this...

~~~
func myfunc(){
    decl f
    f = 11
    return f  
}

decl x = 10
decl y = 10

x = x + 1

if ( x == 17 ) {
    // do something
}

~~~

## Design Goals

### Easy
 - [x] Familiar Syntax C like block structured syntax
 - [x] No semicolons. This is especially useful for learners.

### Parallel
 - [ ] Parallel execution is trivial and straightforward.
 - [ ] Threads are lightweight and first class object

### Safe
 - [x] Stack Based Locals, Heap Based Globals
 - [x] No pointers because no dynamic heap allocation
 - [x] No shared memory between Actors
 - [ ] Broadcast and Narrow cast Messages between Actors
 - [ ] When a Thread exits all the memory associated is released.
 - [ ] Pure Functions, No Side Effects

### Finite State Machines
 - [ ] Many Complex Algorithms are easily described as FSMs
 - [ ] Machines and States are first class objects

### With Bells On (via SFML)
 - [ ] Integrated Physics and Collision Lib
 - [ ] Integrated Graphics and Multimedia IO Library
 - [ ] Integrated High and Low Level Networking Library


## Why?

There was a time when if you wanted to make a game Borland Turbo Pascal was a good way to do it. The language was high level enough that you could focus on the goals. The graphics and so on were integrated with a BGI and/or the VGA was well understood enough to be a stable target. 


![Turbo Pascal Image](https://upload.wikimedia.org/wikipedia/commons/d/df/Turbo_Pascal_7.0_Scrren.png)

Image By Lưu Nguyễn Thiện Hậu - Own work, CC BY-SA 4.0, https://commons.wikimedia.org/w/index.php?curid=75160140


Later Blitz basic and similar high level game Basics were fast and funky especially for writing games on Amigas. Which all the cool kids had.

![Blitz BASIC Logo](https://upload.wikimedia.org/wikipedia/en/6/65/BlitzBasicLogo.gif)

Image By <span title="must have been published or publicly displayed outside Wikipedia">Source</span> (<a href="//en.wikipedia.org/wiki/Wikipedia:Non-free_content_criteria#4" title="Wikipedia:Non-free content criteria">WP:NFCC#4</a>), <a href="//en.wikipedia.org/wiki/File:BlitzBasicLogo.gif" title="Fair use of copyrighted material in the context of BlitzBasic">Fair use</a>, <a href="https://en.wikipedia.org/w/index.php?curid=39065694">Link</a>

Importantly with these kinds of systems the bells and whistles were included. Borland had an integrated editor, and libraries. Similarly Blitz BASIC.



## Installation Instructions

### Linux

 - First Install SFML

~~~
sudo apt-get install libsfml-dev
~~~

 - Clone the Repo

~~~
git clone https://github.com/seanbutler/Morris.git
~~~

 - Launch CLion
 - Press Shift-F9

### Win/Mac

- err, wanna help? 
- i guess its pretty similar on mac being BSD, but windows i dunno really. please help.



## About The Name

### William Morris

![William Morris Image from Wikipedia](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8a/William_Morris_age_53.jpg/440px-William_Morris_age_53.jpg)

"William Morris (24 March 1834 – 3 October 1896) was a British textile designer, poet, novelist, translator and socialist activist associated with the British Arts and Crafts Movement."

https://en.wikipedia.org/wiki/Arts_and_Crafts_movement
https://en.wikipedia.org/wiki/William_Morris

### Morris Dancing

![Morris Dancing Image from Wikipedia](https://upload.wikimedia.org/wikipedia/commons/thumb/9/92/Morris_Dancers%2C_York_%2826579460201%29.jpg/520px-Morris_Dancers%2C_York_%2826579460201%29.jpg)

"Morris dancing is a form of English folk dance usually accompanied by music. It is based on rhythmic stepping and the execution of choreographed figures by a group of dancers, usually wearing bell pads on their shins."

https://en.wikipedia.org/wiki/Morris_dance
