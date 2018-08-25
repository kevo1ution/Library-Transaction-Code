Library System (STL transaction and polymorphism)

README:

compile instructions-
to compile this program do "g++ CPP/*.cpp"
 *Note that when you compile this program, it is best if your terminal/putty is in full screen for ideal user interface


Admin shortcuts-
I created an admin panel to allow for direct changes to data stored in the library data files.
This can change due dates of books, which books are checked out to who, etc.

Important parameters-
 >A patron cannot checkout more than 5 items
 >A patron cannot checkout a book with any fines
 >A patron cannot checkout a book if the patron has any overdue books
 >A patron cannot recheckout a book that is overdue or if the patron has 5 items or any fines
 >The due dates for a book is 2 weeks from when it is checked out and 1 week for AV items
 >Fines are calculated by day with a fee of $0.25 per day or $1.00 for AV items

Save/Load files-
 This program has a unique load and save algorithm. If you want to CHANGE the DUE DATE of a book for grading purposes,
 you can change it in the load/save files. This is helpful because you can test if the program for accurate grading. The
 layout of the file can be easily understood by looking at the load and save functions within the .cpp files.

