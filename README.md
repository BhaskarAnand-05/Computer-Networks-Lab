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

<img src="https://www.simplilearn.com/ice9/free_resources_article_thumb/CRC_1.png">  

---
### 3. Implement stop & wait protocol
Here stop and wait means, whatever the data that sender wants to send, he sends the data to the receiver. After sending the data, he stops and waits until he receives the acknowledgment from the receiver. The stop and wait protocol is a flow control protocol where flow control is one of the services of the data link layer.  

It is a data-link layer protocol which is used for transmitting the data over the noiseless channels. It provides unidirectional data transmission which means that either sending or receiving of data will take place at a time. It provides flow-control mechanism but does not provide any error control mechanism.  

The idea behind the usage of this frame is that when the sender sends the frame then he waits for the acknowledgment before sending the next frame  

<img src="https://static.javatpoint.com/tutorial/computer-network/images/stop-and-wait-protocol.png">  

---

### 4. Implement Sliding window protocol  


The sliding window is a technique for sending multiple frames at a time. It controls the data packets between the two devices where reliable and gradual delivery of data frames is needed. It is also used in TCP (Transmission Control Protocol).

In this technique, each frame has sent from the sequence number. The sequence numbers are used to find the missing data in the receiver end. The purpose of the sliding window technique is to avoid duplicate data, so it uses the sequence number.
Types of Sliding Window Protocol

Sliding window protocol has two types:

    Go-Back-N ARQ
    Selective Repeat ARQ

<b> Go-Back-N ARQ </b>

Go-Back-N ARQ protocol is also known as Go-Back-N Automatic Repeat Request. It is a data link layer protocol that uses a sliding window method. In this, if any frame is corrupted or lost, all subsequent frames have to be sent again.  
                        The size of the sender window is N in this protocol. For example, Go-Back-8, the size of the sender window, will be 8. The receiver window size is always 1.

If the receiver receives a corrupted frame, it cancels it. The receiver does not accept a corrupted frame. When the timer expires, the sender sends the correct frame again. The design of the Go-Back-N ARQ protocol is shown below.  


<img src="https://static.javatpoint.com/tutorial/computer-network/images/sliding-window-protocol.png">   

<b> Selective Repaet ARQ</b>  

Selective Repeat ARQ is also known as the Selective Repeat Automatic Repeat Request. It is a data link layer protocol that uses a sliding window method. The Go-back-N ARQ protocol works well if it has fewer errors. But if there is a lot of error in the frame, lots of bandwidth loss in sending the frames again. So, we use the Selective Repeat ARQ protocol. In this protocol, the size of the sender window is always equal to the size of the receiver window. The size of the sliding window is always greater than 1.

If the receiver receives a corrupt frame, it does not directly discard it. It sends a negative acknowledgment to the sender. The sender sends that frame again as soon as on the receiving negative acknowledgment. There is no waiting for any time-out to send that frame. The design of the Selective Repeat ARQ protocol is shown below.

<img src = "https://static.javatpoint.com/tutorial/computer-network/images/sliding-window-protocol-3.png">  

---

### 5. Show Net id, Host id and Network class of the address
IP stands for Internet Protocol and v4 stands for Version Four (IPv4). IPv4 was the primary version brought into action for production within the ARPANET in 1983.
IP version four addresses are 32-bit integers which will be expressed in decimal notation.
Example- 192.0.2.126 could be an IPv4 address.

<b>Parts of IPv4</b>

<b>Network part:</b> 
    The network part indicates the distinctive variety that’s appointed to the network. The
    network part conjointly identifies the category of the network that’s assigned.  
<b>Host Part: </b>
    The host part uniquely identifies the machine on your network. This part of the IPv4 address
    is assigned to every host. 
    For each host on the network, the network part is the same, however, the host half must
    vary.  
<b>Subnet number: </b>
    This is the nonobligatory part of IPv4. Local networks that have massive numbers of hosts
    are divided into subnets and subnet numbers are appointed to that.  


Different types of IP Addresses exist in the Internet Protocol hierarchy and can be utilised efficiently in a variety of settings based on the demands of hosts on a network. In general, the IPv4 Addressing System is divided into five categories of IP Addresses. All five categories are identified by the first octet of an IP address.

The five Types of classes are:  
Class A  
Class B  
Class C  
CLass D  
CLass E  

![Alt text](C:/Users/bhask_1h/Downloads/Screenshot%202023-02-26%20at%2011-33-49%20C%20program%20to%20find%20class%20of%20an%20IP%20Address.png "Classes")

---

### 6. Implement distance vector routing algorithm.

---

### 7. Implement Link state routing, algorithm.
