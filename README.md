# Lexical-Analyzer-for-BigAdd-Language-with-C

#### Input file that given us:

![image](https://user-images.githubusercontent.com/57726183/154577002-f0c3b61b-bd3b-4426-862e-78a9690ada90.png)

#### Note: I have to fixed the  “”, because it did not match with the casual quotes  “”

#### Output file that expecting from us:

![image](https://user-images.githubusercontent.com/57726183/154577112-d0761636-ee7c-4611-acdf-d1a7a26a4438.png)

#### Output file that my lexical analyzer’s create:

![image](https://user-images.githubusercontent.com/57726183/154577142-24c5d130-90aa-4e73-936b-9d12c44be462.png)

•	As we can see, both expectation analysis and my lexical analyzer’s analysis, are equal to each other.

### Lexical Analyzer Tests

There was 2 error categories that such a lexical analyzer has to detect;
•	A big lexeme is just left open (a comment or a string constant that starts but does not terminate before the end of file) 
•	An unrecognized character is detected in code
I made more error detections . Here is my wrong input files for testing that has to detect errors from code, console output, .lx file.

#### Input file:

![image](https://user-images.githubusercontent.com/57726183/154577517-5d6fd4e4-4842-4e10-afca-c05277a4b553.png)

#### Console output:

![image](https://user-images.githubusercontent.com/57726183/154577554-733a1ec3-5b78-46ca-9e17-0ee92def86bc.png)

#### lx (output) file:

![image](https://user-images.githubusercontent.com/57726183/154577608-8a147b27-212c-455f-a405-460d961101b4.png)

#### Explanation: As I expected, if the curly bracket open and does not close, it should throw exception and shouldn’t write from open point, to the .lx file.

#### Input file:

![image](https://user-images.githubusercontent.com/57726183/154577861-713cd931-544a-4366-87e1-f9fc876c2564.png)

#### Console output:

![image](https://user-images.githubusercontent.com/57726183/154577887-ba130552-5721-44d0-b716-98ceadf4cfcd.png)

#### Explanation: I wrote some unrecognized characters to the input file randomly. My lexical analyzer should detect an error like it’s unrecognized character at X line and it does.      

#### Input file:

![image](https://user-images.githubusercontent.com/57726183/154578093-d5a82c9d-74cb-4008-a581-b98b6e40fd8d.png)

#### Console output:

![image](https://user-images.githubusercontent.com/57726183/154578113-ecdb66b8-0bf9-4ce9-986d-cc0c81405567.png)

#### lx (output) file:

![image](https://user-images.githubusercontent.com/57726183/154578149-d54d0721-7117-4042-b685-68ce7d842a3b.png)

#### Explanation: As I expected, It controls lexically, also controls both command line on the different lines correctly (Open-Close curly brackets) and didn’t find anything wrong, except string quotes ‘ ” ’ when quotes used first time, it understands that its a string quotes and says ‘I shouldn’t take any character until I see the second quote’ And it controls until sees the quote but it couldn’t find. So, throws an exception and other characters doesn’t count for lexeme. 
I also checked –5 form, its invalid and wrong usage. Here is 
#### my input file: 

![image](https://user-images.githubusercontent.com/57726183/154578253-81741542-fc4c-4439-a1bb-928c3c4df03d.png)

and console output: 

![image](https://user-images.githubusercontent.com/57726183/154578289-9a1771b3-4bc7-49c4-9bf0-54616ddcbfb0.png)

#### Note: If it’s unneccessary for the 1st Project just ignore it please.

### Actually, Lexical Analyzer not controls that:
-	Can keyword  come after than identifier?
-	Can identifier come after than keyword?
-	Can int constant come after than keyword? etc.
-	Or can I use a variable name if it doesn’t exist? (haven’t declare yet.)

     These controls will handle on the 2nd Project as Ahmet Egesoy mentioned on the class. So I didn’t control logically, I just made a Lexical analyzer. So that my Lexical analyzer can detect 2 errors as I showed above before and, can give a result that it’s correct or incorrect lexically.



