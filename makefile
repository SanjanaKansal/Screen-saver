#------------------------------------------------------------------------------

CC=g++ 
BIN=./obj
SRC=./src
EXE=./output
LIBS= -lGL -lGLU -lglut -lm -std=gnu++11 -lrt
DOC_SRC=./Doc/
DOC_DST=./
README_PDF=./Doc/README.pdf
CHANGES_PDF= ./Doc/CHANGES.pdf
DST_PDF_README=./README.pdf
DST_PDF_CHANGES= ./CHANGES.pdf

override num_threads ?= 5

#------------------------------------------------------------------------------
cd /tmp
wget http://ftp.gnu.org/gnu/make/make-4.1.tar.gz
tar xvf make-4.1.tar.gz
cd make-4.1/
./configure
make
sudo make install
cd ..
rm -rf make-4.1.tar.gz make-4.1
#------------------------------------------------------------------------------
# make execute num_threads=... for building a new exe. make doc for design document. make clean to remove all .obj and .exe files 

execute: $(EXE)/run
	./$(EXE)/run.out $(num_threads)

$(EXE)/run: $(BIN)/main.o $(BIN)/ball.o 
	$(CC) $(SRC)/main.cpp $(SRC)/ball.h $(SRC)/ext.h -o $(EXE)/run.out $(LIBS)

run1:
	rm -rf obj
	mkdir obj

run2: 
	rm -rf output
	mkdir output

$(BIN)/main.o: $(SRC)/main.cpp $(SRC)/ext.h run1 run2
	$(CC) -c $(SRC)/main.cpp -o $(BIN)/main.o $(LIBS)

$(BIN)/ball.o: $(SRC)/ball.h $(SRC)/ext.h
	$(CC) -c $(SRC)/ball.h -o $(BIN)/ball.o $(LIBS)

doc: $(DOC_SRC)README.tex $(DOC_SRC)CHANGES.tex
	cd Doc && pdflatex README.tex pdflatex CHANGES.tex cd .. ; mv $(README_PDF) $(DST_PDF_README) mv $(CHANGES_PDF) $(DST_PDF_CHANGES)

clean: clean2
	rm $(DOC_SRC)/main.aux $(DOC_SRC)/main.toc $(DOC_SRC)/main.log $(DOC_DST)/log.txt

clean2: 
	rm -r obj output
