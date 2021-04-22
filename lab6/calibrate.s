# Sooyoung Jeon
# CSE 2421 Lab6

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "calibrate.s"  				# optional directive 
.section .rodata					# required directives for rodata 

.data   							# required for file scope data: read-write program data     
#of static storage class 

.global calibrate  					# required directive for every function 
.type calibrate, @function			# required directive  
.text     							# required directive - code begins here 
calibrate: 
	pushq	%rbp   					# stack housekeeping #1 
	movq 	%rsp, %rbp  			# stack housekeeping #2 
	
	leaq	(%rdi), %rdi			# get the starting address of the adjustments array
	
	movq	$0, %rsi				# initialize the index with zero
	movq	$0, %r10				# initialize the max value with zero
	movq	$0, %r11				# initialize the min value with zero
	movq	$0, %r8					# initialize the total value with zero
	
	movw	20(%rdi), %r10w			# put the first element of adjustments array into max
	movw	20(%rdi), %r11w			# put the first element of adjustments array into min
	
	jmp		cond					# start the loop with condition
		
loop:
	movw	20(%rdi, %rsi, 2), %ax	# get the element from the array with index
	incq	%rsi					# decrement the index with 1

									# max
									
	cmpw	%ax, %r10w				# compare the current element with max
	cmovl	%ax, %r10w				# if current element is higher than max, put it in the max

									# min
									
	cmpw	%ax, %r11w				# compare the current element with min
	cmovg	%ax, %r11w				# if current element is lower than min, put it in the min

									# add
									
	cwtl							# convert current value to doubleword type
	cltq							# convert current value to quadword type
	addq	%rax, %r8				# add the current value with total value
	movq	$0, %rax				# reinitialize the current value with 0
	
cond:								
	cmpq	$7, %rsi				# compare the current index with 7
	jle		loop					# if index is equal or less than 7, start the loop

	sarq	$3, %r8					# divide the total value with size of the array (8)
	movw	%r8w, 36(%rdi)			# put the new average value in the struct element avg
	subw	%r11w, %r10w			# subtract the max with min
	movq	%r10, %rax				# return the variability of max and min
	
	leave 							# return stack to original values
	ret 							# return
	.size calibrate, .-calibrate  	#required directive
