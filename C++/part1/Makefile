home = ./
cc = g++
gdb = -g
code = $(home)chapter2/es2.6.2.cpp
target = $(home)chapter2/es2.6.2.out
src = $(shell find ./src -name "*.cpp")
obj = ./bin/mySales_item.o
inc = ./include/


$(target): $(obj)
	@echo "compilling..."
		@$(cc) $(gdb) -I$(inc) $(code) -o $(target) $<
	@echo "done"
	
%.o: $(src)
		@$(cc) -I$(inc) -c $< -o $@
clean:
	@rm -f $(obj)