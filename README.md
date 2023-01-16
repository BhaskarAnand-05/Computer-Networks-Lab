<h1> Computer-Networks-Lab </h1>

## List of Experiments Performed
### 1. Implement Framing techniques - Bit Stuffing, Byte Stuffing,CharacterStuffing.
<b> What is Byte Stuffing?</b>

Byte stuffing is the process of adding an extra byte when there is a flag or escape character in the text. Take an example of byte stuffing as shown in the below diagram.
The sender sends the frame by adding 3 extra ESC bits and the destination machine received the frame and it removes the extra bits to covert the frame into the same message.
<img src="https://digitalnoteshub.com/wp-content/uploads/2021/12/Byte-stuffing-768x432.png">  

<b> What is Bit Stuffing?</b>

Most protocols use a special 8-bit pattern flag 01111110 as the delimiter to define the beginning and the end of the frame. Bit stuffing is done at the sender end and bit removal at the receiver end.
If we have a 0 after five 1s. We still stuff a 0. The receiver will remove the 0. Bit stuffing is also called bit-oriented framing.  

<img src="https://digitalnoteshub.com/wp-content/uploads/2021/12/Bit-Stuffing-768x432.png">

------
### 2. Implement Cyclic redundancy check

------
### 3. Implement stop & wait protocol

------
### 4. Implement Sliding window protocol

------
### 5. Show Net id, Host id and Network class of the address

------
### 6. Implement distance vector routing algorithm.

------
### 7. Implement Link state routing, algorithm.
