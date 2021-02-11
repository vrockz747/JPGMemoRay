# recover
What does this program do?
It recovers lost or deleted jpegs from the memory card of digital cameras.

How does this program work?
Many modern-day digital cameras store their images in .raw format and fortunately, digital cameras tend to store photographs contiguously on memory cards, whereby each photo is stored immediately after the previously taken photo.
This program looks for the signatures of the presence of a jpeg in memory and if found, recovers and outputs it as .jpg image. 

USAGE:-
Compile the recover.c code and give the location of the .raw file as a command line argument.
example: if the name of the file is file.raw and its located in the same directory, input:
./recover file.raw
for testing purpose a card.raw file is provided with the code.


