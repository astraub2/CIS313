#include <stdio.h>
 
int main()
{
  int array[100], n, c, d, swap;
 
  printf("Enter number of elements\n");
  scanf("%d", &n);
 
  printf("Enter %d integers\n", n);
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
 
  printf("Sorted list in ascending order:\n");
 
  for ( c = 0 ; c < n ; c++ )
     printf("%d\n", array[c]);
 
  return 0;
}

.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    
.pos 0x100
Stack:
    
    
//declaring an array
//create an allignment
    .pos 0x104
    .align 4
array:
//populate array
    .long 0x1
    .long 0x2
    .long 0x3
    .long 0x4
Swap:
    //first value
    movl %eax, %edi
    //second value in %edi
    //addl $4, %edi
    //missing stuff
    subl %eax, %edi
    //j swap if eax is greater than edi
    //
    pushl %eax
    pushl %edi
    mrmovl(%eax), %eax
    mrmovl (%edi), %edi
    subl %eax, %edi
    popl %edi
    popl %eax
    
    
    push %esi
    push %ebx
    mrmovl (%eax), %esi


    todays progress

    .pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    
.pos 0x100
Stack:
  .pos 0
init: 
    irmovl Stack, %esp    # Set up stack pointer  
  irmovl Stack, %ebp    # Set up base pointer   
  call Main   # Execute main program
  halt
  
  # Terminate program 
  .align 4 
array:  
    .long 0x2
    .long 0x1
    .long 0x3
    .long 0x4
Main:
    pushl %ebp 
  rrmovl %esp,%ebp
  irmovl $4,%eax  
  pushl %eax          #array length is in stack
  irmovl array,%edx
  pushl %edx        # Push array into stack
  call Swaper
    
  #pushl %edx
    #rrmovl %esp,%ebp
    #irmovl $4, %ebx
    #irmovl $5, %eax
    #subl %ebx, %eax
Swaper:
    pushl %ebp
  rrmovl %esp,%ebp
  mrmovl 8(%ebp),%ecx   # ecx = array
  mrmovl 12(%ebp),%edx  # edx = array length
  ##this is the inner loop
  mrmovl (%ecx),%esi      # %esi= first value in array
  rrmovl %ecx, %eax       # 
  irmovl $4,%ebx          # 
  addl %ebx,%eax         # increment array (%eax)=next value
  mrmovl (%eax), %eax     # !!%eax=next value!!
  #conditional compare
  #then swap if condition is true
  #ecx, esi, edx and eax are off limits
  xorl %ebx, %ebx
  #need placeholder for %eax
  rrmovl %eax, %edi
  subl %esi, %edi
  #check if value of second-first>=0
  addl %ebx, %edi
  jge End
Loop:
    #this is where the elements get swapped
    # swapping %esi(first) and %eax(second) in %ecx(array)
    #dont use %edx (counter)
    rrmovl %eax, %ebx
    #set first element in array
    rmmovl %eax, (%ecx)
    #set second element in array
    irmovl $4,%edi
    addl %edi, %ecx
    rmmovl %esi, (%ecx)
    

End:  
    rrmovl %ebp,%esp
  popl %ebp
  ret

3:00
.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    
.pos 0x100
Stack:
  .pos 0
init: 
    irmovl Stack, %esp    # Set up stack pointer  
  irmovl Stack, %ebp    # Set up base pointer   
  call Main   # Execute main program
  halt
  
  # Terminate program 
  .align 4 
array:  
    .long 0x4
    .long 0x3
    .long 0x2
    .long 0x1
Main:
    pushl %ebp 
  rrmovl %esp,%ebp
  irmovl $4,%eax  
  pushl %eax          #array length is in stack
  irmovl array,%edx
  pushl %edx        # Push array into stack
  call Swaper
    
  #pushl %edx
    #rrmovl %esp,%ebp
    #irmovl $4, %ebx
    #irmovl $5, %eax
    #subl %ebx, %eax
Swaper:
    pushl %ebp
  rrmovl %esp,%ebp
  mrmovl 8(%ebp),%ecx   # ecx = array
  mrmovl 12(%ebp),%edx  # edx = array length
  ##this is the inner loop
  mrmovl (%ecx),%esi      # %esi= first value in array
  rrmovl %ecx, %eax       # 
  irmovl $4,%ebx          # 
  addl %ebx,%eax         # increment array (%eax)=next value
  mrmovl (%eax), %eax     # !!%eax=next value!!
  xorl %ebx, %ebx
  rrmovl %eax, %edi
  subl %esi, %edi
  #check if value of second-first>=0
  addl %ebx, %edi
  jge End
Loop:
    #this is where the elements get swapped
    # swapping %esi(first) and %eax(second) in %ecx(array)
    #dont use %edx (counter)
    rrmovl %eax, %ebx
    #set first element in array
    rmmovl %eax, (%ecx)
    #set second element in array
    irmovl $4,%edi
    addl %edi, %ecx
    rmmovl %esi, (%ecx)
    #we need to know if values are swapped
    #subl  %edi, %ecx
    #mrmovl (%ecx), %esi
    #addl %edi, %ecx
    #mrmovl (%ecx), %eax
    irmovl $-1,%edi
    addl %edi, %edx #decrement counter
    jne Loop
    

End:  
    rrmovl %ebp,%esp
  popl %ebp
  ret
  
4:30
.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    
.pos 0x100
Stack:
  .pos 0
init: 
    irmovl Stack, %esp    # Set up stack pointer  
  irmovl Stack, %ebp    # Set up base pointer   
  call Main   # Execute main program
  halt
  
  # Terminate program 
  .align 4 
array:  
    .long 0x3
    .long 0x4
    .long 0x2
    .long 0x1
Main:
    pushl %ebp 
  rrmovl %esp,%ebp
  irmovl $3,%edx      # edx = array length-1
  #I was having trouble getting the jne to work
  irmovl array,%ecx   # ecx = array
  call Look
    
Look:
    irmovl $-1,%ebx         # 
  addl   %ebx,%edx          # Count--
  andl   %edx,%edx
  jl    End             # Stop when 0
    #if counter=0, end
  ##this is the inner loop
  mrmovl (%ecx),%esi      # %esi= first value in array
  rrmovl %ecx, %eax       # 
  irmovl $4,%ebx          # 
  addl %ebx,%eax          # increment array (%eax)=next value
  mrmovl (%eax), %eax     # !!%eax=next value!!
  xorl %ebx, %ebx
  rrmovl %eax, %edi
  subl %esi, %edi
  #check if value of second-first< 0
  #if so swap values
  andl %edi, %edi
  
  jl Swap
  
  #otherwise increment position in array 
  #and check those values
  irmovl $4,%ebx
  addl %ebx, %ecx
  jmp Look
  
  irmovl $-1,%ebx         # 
  addl %ebx,%edx          # Count--
  andl   %edx,%edx
  jne    End             # Stop when 0
    
Swap:#swap values
    #increment point in array
    #this is where the elements get swapped
    # swapping %esi(first) and %eax(second) in %ecx(array)
    #dont use %edx (counter)
    rrmovl %eax, %ebx
    #set first element in array
    rmmovl %eax, (%ecx)
    #set second element in array
    irmovl $4,%edi
    #pointer moves forward 1 in array
    addl %edi, %ecx
    rmmovl %esi, (%ecx)
    jmp Look
End:  
    rrmovl %ebp,%esp
  popl %ebp
  ret
  
5:30
.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    
.pos 0x100
Stack:
  .pos 0
init: 
    irmovl Stack, %esp    # Set up stack pointer  
  irmovl Stack, %ebp    # Set up base pointer   
  call Main   # Execute main program
  halt
  
  # Terminate program 
  .align 4 
array:  
    .long 0x3
    .long 0x4
    .long 0x2
    .long 0x1
Main:
    pushl %ebp 
  rrmovl %esp,%ebp
  irmovl $3,%edx      # edx = array length-1
  rrmovl %edx, %edi   #edi is a copy of the counter
  #I was having trouble getting the jne to work
  irmovl array,%ecx   # ecx = array
  
  call Look
  
Outer_Loop:
    #for your outer loop
  #you can use %edi and %ebx
  #this executes array.length() times
  #each time the counter for Look will -1
  #edx is array length that will update
  #edi will be number of iterations left
  #mrmovl (%ecx), %ebx
  #edi is a copy of the counter
  irmovl $-1, %ebx
  addl %ebx, %edi
  rrmovl %edi, %edx
  
  
  call Look
Add_back:
    #for moving back to the start of the array
    irmovl $4,%ebx
    subl %ebx, %ecx
    irmovl $-1, %ebx
    addl %ebx, %edi
    andl %edi, %edi
    jl Outer_Loop
    
    
    

Look:
    irmovl $-1,%ebx         # 
  addl   %ebx,%edx        # Count--
  andl   %edx,%edx
  jl    Add_back             # Stop when 0
    #if counter=0, end
  ##this is the inner loop
  mrmovl (%ecx),%esi      # %esi= first value in array
  rrmovl %ecx, %eax       # 
  irmovl $4,%ebx          # 
  addl %ebx,%eax          # increment array (%eax)=next value
  mrmovl (%eax), %eax     # !!%eax=next value!!
  xorl %ebx, %ebx
  rrmovl %eax, %edi
  subl %esi, %edi
  #check if value of second-first< 0
  #if so swap values
  andl %edi, %edi
  
  jl Swap
  
  #otherwise increment position in array 
  #and check those values
  irmovl $4,%ebx
  addl %ebx, %ecx
  jmp Look
  
    
Swap:#swap values
    #increment point in array
    #this is where the elements get swapped
    # swapping %esi(first) and %eax(second) in %ecx(array)
    #dont use %edx (counter)
    rrmovl %eax, %ebx
    #set first element in array
    rmmovl %eax, (%ecx)
    #set second element in array
    irmovl $4,%edi
    addl %edi, %ecx #pointer moves forward 1 in array
    rmmovl %esi, (%ecx)
    jmp Look
End:  
    rrmovl %ebp,%esp
  popl %ebp
  ret
  
7:00
.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    
.pos 0x100
Stack:
  .pos 0
init: 
    irmovl Stack, %esp    # Set up stack pointer  
  irmovl Stack, %ebp    # Set up base pointer   
  call Main   # Execute main program
  halt
  
  # Terminate program 
  .align 4 
array:  
    .long 0x3
    .long 0x4
    .long 0x2
    .long 0x1
    
Main:
    pushl %ebp 
  rrmovl %esp,%ebp
  irmovl $3,%edx      # edx = array length-1
  rrmovl %edx, %edi   #edi is a copy of the counter
  #I was having trouble getting the jne to work
  irmovl array,%ecx   # ecx = array
  
  call Look
  
Outer_Loop:
    #for your outer loop
  #you can use %edi and %ebx
  #this executes array.length() times
  #each time the counter for Look will -1
  #edx is array length that will update
  #edi will be number of iterations left
  #mrmovl (%ecx), %ebx
  #edi is a copy of the counter
  #rrmovl %edx, %edi   #reassign inner counter
  irmovl $-1, %ebx
  addl %ebx, %edi    #decrement inner counter
  rrmovl %edi, %edx #decrement master counter
  call Look
  
Add_back:
    #for moving back to the start of the array
    irmovl $4,%ebx
    subl %ebx, %ecx #move back an element
    irmovl $-1, %ebx
    addl %ebx, %edi
    
    andl %edi, %edi
    # repeat this as long as %edi>0
    jl Add_back
    #after it does so many shifts it skips back 
    jmp Outer_Loop
    
    
    

Look:
    irmovl $-1,%ebx         # 
  addl   %ebx,%edx        # Count--
  andl   %edx,%edx
  jl    Add_back             # Stop when 0
    #if counter=0, end
  ##this is the inner loop
  mrmovl (%ecx),%esi      # %esi= first value in array
  rrmovl %ecx, %eax       # 
  irmovl $4,%ebx          # 
  addl %ebx,%eax          # increment array (%eax)=next value
  mrmovl (%eax), %eax     # !!%eax=next value!!
  xorl %ebx, %ebx
  rrmovl %eax, %ebx
  subl %esi, %ebx
  #check if value of second-first< 0
  #if so swap values
  andl %ebx, %ebx
  
  jl Swap
  
  #otherwise increment position in array 
  #and check those values
  irmovl $4,%ebx
  addl %ebx, %ecx
  jmp Look
  
    
Swap:#swap values
    #increment point in array
    #this is where the elements get swapped
    # swapping %esi(first) and %eax(second) in %ecx(array)
    #dont use %edx (counter)
    rrmovl %eax, %ebx
    #set first element in array
    rmmovl %eax, (%ecx)
    #set second element in array
    irmovl $4,%ebx
    addl %ebx, %ecx #pointer moves forward 1 in array
    rmmovl %esi, (%ecx)
    jmp Look
End:  
    rrmovl %ebp,%esp
  popl %ebp
  ret




7:30
.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    
.pos 0x100
Stack:
  .pos 0
init: 
    irmovl Stack, %esp    # Set up stack pointer  
  irmovl Stack, %ebp    # Set up base pointer   
  call Main   # Execute main program
  halt
  
  # Terminate program 
  .align 4 
array:  
    .long 0x3
    .long 0x4
    .long 0x2
    .long 0x1
    
Main:
    pushl %ebp 
  rrmovl %esp,%ebp
  irmovl $3,%edx      # edx = array length-1
  rrmovl %edx, %edi   #edi is a copy of the counter
  #I was having trouble getting the jne to work
  irmovl array,%ecx   # ecx = array
  
  call Look
  
Outer_Loop:
    #for your outer loop
  #this executes array.length() times
  #each time the counter for Look will -1
  #edx is array length that will update
  #edi will be number of iterations left
  
  rrmovl %esi, %edi   #reassign counter
  irmovl $-1, %ebx
  addl %ebx, %edi    #decrement counter
  rrmovl %edi, %edx #decrement master counter
  #if master counter is 0, end
  andl %edx, %edx
  je End
  call Look
  
Add_back:
    #for moving back to the start of the array
    irmovl $4,%ebx
    subl %ebx, %ecx #move back an element
    irmovl $-1, %ebx
    addl %ebx, %edi
    
    andl %edi, %edi
    # repeat this as long as %edi>0
    jge    Add_back 
    #after it does so many shifts it skips back 
    jmp Outer_Loop
    
    
    

Look:
    irmovl $-1,%ebx         # 
    rrmovl %edi, %esi       #perserve the counter
  addl   %ebx,%edx        # Count--
  andl   %edx,%edx
  jl    Add_back             # Stop when 0
    #if counter=0, end
  ##this is the inner loop
  mrmovl (%ecx),%esi      # %esi= first value in array
  rrmovl %ecx, %eax       # 
  irmovl $4,%ebx          # 
  addl %ebx,%eax          # increment array (%eax)=next value
  mrmovl (%eax), %eax     # !!%eax=next value!!
  xorl %ebx, %ebx
  rrmovl %eax, %ebx
  subl %esi, %ebx
  #check if value of second-first< 0
  #if so swap values
  andl %ebx, %ebx
  
  jl Swap
  
  #otherwise increment position in array 
  #and check those values
  irmovl $4,%ebx
  addl %ebx, %ecx
  jmp Look
  
    
Swap:#swap values
    #increment point in array
    #this is where the elements get swapped
    # swapping %esi(first) and %eax(second) in %ecx(array)
    #dont use %edx (counter)
    rrmovl %eax, %ebx
    #set first element in array
    rmmovl %eax, (%ecx)
    #set second element in array
    irmovl $4,%ebx
    addl %ebx, %ecx #pointer moves forward 1 in array
    rmmovl %esi, (%ecx)
    jmp Look
End:  
    rrmovl %ebp,%esp
  popl %ebp
  ret
  
.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    
.pos 0x100
Stack:
  .pos 0
init: 
    irmovl Stack, %esp    # Set up stack pointer  
  irmovl Stack, %ebp    # Set up base pointer   
  call Main   # Execute main program
  halt
  
  # Terminate program 
  .align 4 
array:  
    .long 0x3
    .long 0x4
    .long 0x2
    .long 0x7
    .long 0x4
    .long 0x5
    .long 0x1
    .long 0x4
    .long 0x5
    .long 0x5
    
Main:
    pushl %ebp 
  rrmovl %esp,%ebp
  irmovl $9,%edx      # edx = array length-1
  rrmovl %edx, %edi   #edi is a copy of the counter
  #I was having trouble getting the jne to work
  irmovl array,%ecx   # ecx = array
  
  call Look
  
Outer_Loop:
    #for your outer loop
  #this executes array.length() times
  #each time the counter for Look will -1
  #edx is array length that will update
  #edi will be number of iterations left
  
  rrmovl %esi, %edi   #reassign counter
  irmovl $-1, %ebx
  addl %ebx, %edi    #decrement counter
  rrmovl %edi, %edx #decrement master counter
  #if master counter is 0, end
  andl %edx, %edx
  je End
  call Look
  
Add_back:
    #for moving back to the start of the array
    irmovl $4,%ebx
    subl %ebx, %ecx #move back an element
    irmovl $-1, %ebx
    addl %ebx, %edi
    
    andl %edi, %edi
    # repeat this as long as %edi>0
    jg    Add_back 
    #after it does so many shifts it skips back 
    jmp Outer_Loop
    
    
    

Look:
    irmovl $-1,%ebx         # 
    rrmovl %edi, %esi       #perserve the counter
  addl   %ebx,%edx        # Count--
  andl   %edx,%edx
  jl    Add_back             # Stop when 0
    #if counter=0, end
  ##this is the inner loop
  mrmovl (%ecx),%esi      # %esi= first value in array
  rrmovl %ecx, %eax       # 
  irmovl $4,%ebx          # 
  addl %ebx,%eax          # increment array (%eax)=next value
  mrmovl (%eax), %eax     # !!%eax=next value!!
  xorl %ebx, %ebx
  rrmovl %eax, %ebx
  subl %esi, %ebx
  #check if value of second-first< 0
  #if so swap values
  andl %ebx, %ebx
  
  jl Swap
  
  #otherwise increment position in array 
  #and check those values
  irmovl $4,%ebx
  addl %ebx, %ecx
  jmp Look
  
    
Swap:#swap values
    #increment point in array
    #this is where the elements get swapped
    # swapping %esi(first) and %eax(second) in %ecx(array)
    #dont use %edx (counter)
    rrmovl %eax, %ebx
    #set first element in array
    rmmovl %eax, (%ecx)
    #set second element in array
    irmovl $4,%ebx
    addl %ebx, %ecx #pointer moves forward 1 in array
    rmmovl %esi, (%ecx)
    jmp Look
End:
    #1
    mrmovl (%ecx), %eax
    irmovl $4,%ebx
    addl %ebx, %ecx
    pushl %eax
    #2
    mrmovl (%ecx), %eax
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    #3
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    #4
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    #5
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    #6
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    #7
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    #8
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    #9
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    #10
    addl %ebx, %ecx
    mrmovl (%ecx), %eax
    pushl %eax
    
    rrmovl %ebp,%esp
  popl %ebp
  ret

























  

























  

























  

























  
  
  

























  


