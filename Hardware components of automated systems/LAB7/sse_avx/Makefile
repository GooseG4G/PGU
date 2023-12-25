%.o: %.s
	nasm -felf64 $< -o $@

%: %.o
	ld $< -o $@
#empty
% : %.s 