**A list of the name of the students in the team**
The bachelor team was:
- Stian Sørslett
- Benjamin Skinstad

But only I (Stian) have professional programming this semester. 

**A list of links to any other repos connected to the project**

I have added any snippets of code I go through in discussion in this repo, so no links needed.

For code i consider good we have:
- source.cpp

For code i consider bad we have:
- medaljer.h
- medaljer.cpp

For code before and after refactoring we have:


**Group discussion**
**Strenghts and weaknesses of languages you used in your project:**

Our application is made using Unity. Therefore we only have a few choices of language as far as we understand, and only one of them seems to be the obvious choice. The main choices, maybe only choices actually, is C# and UnityScript (which is a Unity version of javascript), and we decided on using C#. There seem to be an even mix of documentation so that's not really a point to which we pick after. C# is a very popular language, so it's easy to find questions and answers online if we need to google something. It is widely used and therefore has good documentation in our opinion. It is object oriented which we feel is a plus. We can’t really think of weaknesses for it. We know one weakness is that it is very Windows oriented, but that doesn’t really matter to us as Unity helps make the application available on the platforms we want supported. 

**How you controlled process and communication systems during development**

To start off we were a very small group, only two people. This provided both challenges and boons. On the development side I would say it was bad at times because of the little amount of manpower we had to work with, being half the amount of people a lot of the other bachelor groups were. We do however think that on the side of communication it was easier for us. This because we were less people to account for and less opinions to keep track of. I have several times used trello or other boards as a way to keep track of tasks needed to be done, and to keep track of work we need to do during sprints and the likes. Under the bachelor however, we opted away from this. Our reasons for this were a couple. Firstly, and probably most importantly, we thought the reward for keeping the board fed and updated was more work than needed for two people, and secondly, we felt the communication channels we already were using were adequate. 

So what we ended up using was mainly discord, where we created our own chat for tracking work, talking about ideas and keeping track of notes and documents. We also had a work diagram we went through every five weeks to see if we were on track, what was left, what we were going to do in the next sprint and what we had to cut. These two have felt sufficient for us through the entire process. Now, i don’t think this is a valid route to go for everyone as a discord channel can get cluttered very fast with multiple people. But we do think this was a valid option for our 2 man team.   

**Use of version control systems, ticket tracking, branching, version control**

On the basis of using git and keeping a version control, using branching and the like i am very positive about it. I (the writer) personally use this in all the projects I can, but the group decided not to focus much time on this during the project. There are a few reasons why we have not used git much. The big one is that we have continuously met difficulties with the uploading of large files from Unity using git. This was a big deterrent for us to continue developing with it. We have also heard and experienced in earlier private and school projects the quirky nature of merge conflicts when pushing unity projects, and the experience of sitting late on a game jam, having all the last work disappear because of merge conflicts doing this is vivid in my imagination. We also have the issue of github not letting you upload files over a certain size on a free account. This last one can be avoided by using the schools gitlab and upload there, but there it requires ssh keys to upload this big a files, and while that is very doable it was yet another reason we got scared off due to non of us being familiar with ssh keys as we both had been using https up to this point. It was all in all reasons why we felt using git would be more of a hassle than a boon. 

We also felt like the way we worked was adequate without the need for version control. We generally only worked in separate scenes, except during the first month when we needed to develop the first part of our project. We have been developing a VR project, which has kept us largely locked to the VR lab. This made it so we didn’t have a need for being able to clone projects over several computers, and the very few times we needed to do this we could just use a large usb device. 

This does not mean there isn’t generally a very good idea to use git. The ability to go back to older, functioning parts of the project in case you break everything is a very positive thing, but we haven’t felt the need for it in our two man project. There is also the ability to track what has been done and where bugs have been introduced, but again, this has been largely avoided by the fact that we are only two, which for the most part have been working in different scenes all the time. One place we do miss the power of git is to have specific notes to go back to during the writing of our report. This is because it is harder than anticipated to remember when some of our functionality was done or changed. 


**Link to programming style guide including how to comment code.**

**Use of libraries and integration of libraries Professionalism in your approach to software development**

Here we have gotten fairly easy off during our thesis. Using libraries with Unity is very easy. It is mainly going on the Unity Asset Store, finding the package you are looking for, and clicking on import. Unity will then take care of integrating said library into our project by itself. I think a lot of tasks would require a better structure over third party libraries, and the discussion of what is needed and what isn’t to avoid bloating where necessary, but our project has had little contact with this as everything gets structured for us when we import from Unity.

**Use of code review**

We have been using code reviewing quite regularly during our development. This is something we have done by straight up code reviewing after the other person has done their task, or through reading over code the other does during pair programming. This is something we have great experience with as there is usually in our experience a lot easier to root out buggs and ugly code when both group members have been over it. It also then helps lessen the technical debt we otherwise would have to repay later if the code review and pair programming weren’t used. And we have also an example of where going over the code in a review together helps make it better and squish bugs we had in our project (I will talk about this in the before and after refactoring). The value of reviewing the code helped very much on this particular problem. While the group has cut corners on some parts, we did not do so on the part of reviewing each other's work, and this might not only be good for the project we have been working on now, but also to feel more comfortable with others reviewing our work. 


**A link to, and discussion of, code you consider good.**

When i first tried to rack my brain around what I consider good code it hit me that this was a lot harder then i first anticipated. Because truthfully, what is, or perhaps what was, good code for me? I realized when thinking about this that I have grown since i started here some few semesters ago, not in height, a bit in girth, but most off all as a programmer. I am by far fully developed as a programmer, and I am probably years away from daring to call myself experienced, but I must have grown a little bit. The reason I am saying this is that when I think of what I consider good code, it is fundamentally different from what I thought of as good code, and I think it took this class for me to fully appreciate this. Because as several of my classes try to teach us best practices when developing, this is the first class I feel like I have gotten the question “why do you consider this good code”, and thinking about me two years ago, and me now, I would say very different things.

Okay, so, my good example is a piece of code I consider very good, and while sticking to me reminiscing of days past, I felt like it was fitting to use one of the first lines of code I ever wrote. You might think of this as a joke, but I have picked Hello World for C++(Here named Source.cpp). My old self would not call this good code, because its small, it's not commented, the sentence “Hello World” is not stored in a char array(the last one was my, maybe, last jabb at Frode), but the crux of the matter is, I wouldn’t have considered calling it good code, and i would never have thought of putting it as my pick for good code if i ever where to be asked to discuss it. While now… I not only put it up as my pick for good code I am willing to write a discussion about, but I actually do it. I consider this good code, and I think of it as that for a few reasons. Firstly, it does what it’s supposed to, and it does it beautifully. What I mean when saying that is this, it displays a line of text. That is the project's job, but that's not all it does. It also provides the programmer with a visual confirmation of their setup being correct, as they are easily able to see if they can run, debug and display the code in the manner the project wants it to, AND, if that wasn’t enough, it provides new programmers with a metaphorical way of saying to the world that they are future programmers in the making, and giving them a sense of accomplishment very early on by just being able to run a very simple program.

On a more technical note I also think it meets the criteria of what i consider good, or pretty, code now. It is very short and concise. It does what it’s supposed to with no extra frills. It isn’t overly commented, it actually manages to show what it does, and how it does it, to everyone(even most new programmers) without using a single line of commenting. It doesn’t deal with a primitive overuse or have tiny differences(understandably, this is because it doesn’t have anything to have tiny differences in or use any types), it has no bugs, and no bloated functionality or repeated functions.

All this combined is why I think this is good code. 

**A link to, and discussion of, code you consider bad.**

As with finding some good code, finding bad code brings me into an existential crisis of its own. Maybe not a good one in the sense the last taks gave me confidence in my own growth, this case gives me a feeling of impending doom as I read over my past works and projects. Making me constantly go “Th.. this is what i have done? What is this i have done… I am supposed to find a job in this field!?”. Which, you know, is as good a start on my day as any. I have picked out one file, two, a cpp file and a header file(Here called medaljer.h and medaljer.cpp). This is probably not my worst work ever, but it is an average work from past me, and as good a place as any to find faults and ugliness I think.

If I were to put this in Lord of the Rings terms (after all, what is a handin to a New Zealander without a LOTR reference) then my average code from two years ago would be an ork to the Hello Worlds Elfness. The shortest of the two files are the header. And it is not much i want to bring up here, I am not sure how nitpicky i want to go. I might ask myself, do I really need a struct to keep track of the int values of medals? Do they need to be ints? And did i really need to name every function name in norwegian? The answer to all these questions might very well be no. Which all in all probably would have made the code prettier to look at.

The real meat of the code is in the cpp file, where all the functions are. First off I will name my incessant commenting as a stain on my eyes. Yes, it most likely was a Frode class, I don’t recall, but I must have been commenting as to get into Frodes good graces then, because I do not believe I would need to comment that the function called “writeToFile()” writes to file… On line 118 that is literally what i have done, Medals::writesToFile() //Writes medals to file.

And again with the norwegian. I do not like that I wrote everything in norwegian, like, at all. The program is also fairly bloated. It is hard to read, and while i do think the naming of values and functions is fairly on point… Why did I write it in norwegian!? And why do I comment on every function just rewriting the name of each function. When naming is good you should be able to read what the function does from the name, you don’t need the exact same on a comment. 

It doesn’t help with the bloating either that I apparently didn’t find or had made a way of differentiating the medals from one another, so i seem to do everything three times (why did I even put it in a struct then…). I have also realised that while there is almost more comments than code in this file, the comments that are there usually explain exactly what the line in front of it does and doesn’t explain the overarching use of the file or what it is meant to be tying into. 

I am also not entirely sure how well the program actually runs… And since there are 0% tests or any sign of test driven development I have no idea if what it does is correct.

All of these parts make this ugly code in my opinion.

**A link to two pieces of code, a before and after refactoring. This will include a discussion of why the code was refactored**

**A personal reflection about professionalism in programming**
