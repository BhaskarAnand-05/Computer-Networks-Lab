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

---

### 2. Implement Cyclic redundancy check

<b> What is Cyclic Redundancy Check ??🤔🤔</b>

The CRC is a network method designed to detect errors in the data and information transmitted over the network. This is performed by performing a binary solution on the transmitted data at the sender’s side and verifying the same at the receiver’s side.

The term CRC is used to describe this method because Check represents the “data verification,” Redundancy refers to the “recheck method,” and Cyclic points to the “algorithmic formula.”

<b> CRC Terms and Attributes👈 </b>

As discussed in the previous section, CRC is performed both at the sender and the receiver side. CRC applies the CRC Generator and CRC Checker at the sender and receiver sides, respectively.

The CRC is a complex algorithm derived from the CHECKSUM error detection algorithm, using the MODULO algorithm as the basis of operation. It is based on the value of polynomial coefficients in binary format for performing the calculations.

For Example:

    1. x2+x+1 (polynomial equation)
    2. Converting to binary format-
          -Going through the equation, we have value at the 0th position (x), value at the 1’st position (x), and the 2nd position (x2).
          -So, the binary value will be - [111]
    3. Similarly for equation, [x2+1], the binary value will be, [101].
    4. There is no value at the “x” position, so the value is [0].

## <img src="https://www.simplilearn.com/ice9/free_resources_article_thumb/CRC_1.png">

### 3. Implement stop & wait protocol

---

### 4. Implement Sliding window protocol

---

### 5. Show Net id, Host id and Network class of the address

---

### 6. Implement distance vector routing algorithm.

---

### 7. Implement Link state routing, algorithm.
