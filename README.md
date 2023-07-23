# JPGMemoRay <br>
What does this program do?  
It recovers lost or deleted jpegs from the memory card of digital cameras.
<br>

## How does this program work?
Many modern-day digital cameras store their images in .raw format. Fortunately, digital cameras tend to store photographs in a contiguous ray of blocks on memory cards, whereby each photo is stored immediately after the previously taken photo.<br>
This program looks for the signatures of the presence of a jpeg in memory and if found, recovers and outputs it as .jpg image. 

## USAGE:<br>
Compile the `recover.c` code and give the location of the `.raw` file as a command line argument.<br>
Example: if the name of the file is `file.raw` and its located in the same directory:<br>
```
./recover file.raw
```
For testing purposes a `card.raw `file is provided with the code.

## Contribution:-<br>
I want you to know that contributions are always welcome.<br>
If you want to contribute to this project, start a PR, and I will look into it within a few days.
