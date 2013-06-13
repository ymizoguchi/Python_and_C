LIBS=-lpython2.6
INCLUDE=-I/opt/local/Library/Frameworks/Python.framework/Versions/2.6/include/python2.6/ -I/opt/local/include/eigen3
LDFLAGS=-L/opt/local/lib

all: formula.o formula.so formulamodule.so

formula.o: formula.c
	gcc -fpic -o formula.o -c formula.c
formula.so: formula.o
	gcc $(LDFLAGS) -shared formula.o -o formula.so
formulaWrapper.o: formulaWrapper.c
	gcc $(INCLUDE) -fpic -o formulaWrapper.o -c formulaWrapper.c
formulamodule.so: formula.o formulaWrapper.o
	gcc $(LDFLAGS) -shared formula.o formulaWrapper.o -o formulamodule.so $(LIBS)
formulatest: formulamodule.so formulatest.py
	python2.6 formulatest.py

pythonformula: formula.so pythonformula.py
	python2.6 pythonformula.py

clean:
	rm -rf *~ *.o test *.so


