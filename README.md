# Lexical-Analyzer-for-BigAdd-Language-with-C

Input file that given us:

![image](https://user-images.githubusercontent.com/57726183/154577002-f0c3b61b-bd3b-4426-862e-78a9690ada90.png)

Note: I have to fixed the  “”, because it did not match with the casual quotes  “”

Output file that expecting from us:

![image](https://user-images.githubusercontent.com/57726183/154577112-d0761636-ee7c-4611-acdf-d1a7a26a4438.png)

Output file that my lexical analyzer’s create:

![image](https://user-images.githubusercontent.com/57726183/154577142-24c5d130-90aa-4e73-936b-9d12c44be462.png)

•	As we can see, both expectation analysis and my lexical analyzer’s analysis, are equal to each other.

### Lexical Analyzer Tests

There was 2 error categories that such a lexical analyzer has to detect;
•	A big lexeme is just left open (a comment or a string constant that starts but does not terminate before the end of file) 
•	An unrecognized character is detected in code
I made more error detections . Here is my wrong input files for testing that has to detect errors from code, console output, .lx file.

Input file:

![image](https://user-images.githubusercontent.com/57726183/154577517-5d6fd4e4-4842-4e10-afca-c05277a4b553.png)

Console output:

![image](https://user-images.githubusercontent.com/57726183/154577554-733a1ec3-5b78-46ca-9e17-0ee92def86bc.png)

lx (output) file:

![image](https://user-images.githubusercontent.com/57726183/154577608-8a147b27-212c-455f-a405-460d961101b4.png)

Explanation: As I expected, if the curly bracket open and does not close, it should throw exception and shouldn’t write from open point, to the .lx file.                                                       
