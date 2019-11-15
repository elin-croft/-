home = ./
code = $(home)chapter2/es2.6.2.cpp
target = $(home)chapter2/es2.6.2.out
src = $(shell find ./src -name "*.cpp")
obj = ./bin/mySales_item.o
inc = ./include/

%.o: $(src)
		g++ -I $(inc) -c $< -o $@
$(target): $(obj)
		g++ -I$(inc) $(code) -o $(target) $<

	@rm -f $(obj)