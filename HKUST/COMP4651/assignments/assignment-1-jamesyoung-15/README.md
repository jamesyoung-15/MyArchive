[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/6x3xYnv0)
# COMP4651 Assignment-1: EC2 Measurement (2 questions, 4 marks)

### Deadline: 23:59, Mar 2, Saturday

---

### Name: Young, James Yang
### Student Id: 20740589
### Email: jyyoungaa@connect.ust.hk

---

## Question 1: Measure the EC2 CPU and Memory performance

1. (1 mark) Report the name of measurement tool used in your measurements (you are free to choose *any* open source measurement software as long as it can measure CPU and memory performance). Please describe your configuration of the measurement tool, and explain why you set such a value for each parameter. Explain what the values obtained from measurement results represent (e.g., the value of your measurement result can be the execution time for a scientific computing task, a score given by the measurement tools or something else).

    > I used the tool `Phoronix Test Suite` for measuring CPU and memory performance. I used 7zip compression test for CPU testing, where I ran the command `phoronix-test-suite run pts/compress-7zip` as suggested in the tutorial. The test measures the performance of a system in compressing and decompressing files using the 7zip compression algorithm to evaluate the CPU's performance and efficiency. The unit used to evaluate the performance is MIPS (million instruction per second), measuring number of millions of instructions that can be executed by the CPU in one second. For measuring memory I used the command `phoronix-test-suite run pts/ramspeed`, measuring how quickly the system can read and write to RAM. I set the configuration to only measure copy performance with integer so that the test wouldn't take too long. The result is in MB/s, which tells us the rate data can be transferred to and from RAM.
    
    

2. (1 mark) Run your measurement tool on general purpose `t2.small` (1 vCPU, 2 GiB Memory), `m5.large` (2 vCPU, 8 GiB Memory), and `c5d.large` (2 vCPU, 4 GiB Memory) Linux instances, respectively, and find the performance differences among these instances. Launch all the instances in the **US East (N. Virginia)** region. Does the performance of EC2 instances increase commensurate with the increase of the number of vCPUs and memory resource?

    In order to answer this question, you need to complete the following table by filling out blanks with the measurement results corresponding to each instance type.

    | Size        | CPU performance | Memory performance |
    | ----------- | --------------- | ------------------ |
    | `t2.small` |     3564 MIPS    |    8855.31 MB/s   |
    | `m5.large`  |    7226 MIPS    |    14554.67 MB/s   |
    | `c5d.large` |    8088 MIPS    |    14756.78 MB/s   |

    > Region: US East (N. Virginia). Use `Ubuntu Server 22.04 LTS (HVM)` as AMI.

## Question 2: Measure the EC2 Network performance

1. (1 mark) The metrics of network performance include **TCP bandwidth** and **round-trip time (RTT)**. Within the same region, what network performance is experienced between instances of the same type and different types? In order to answer this question, you need to complete the following table.

    | Type                      | TCP b/w (Mbps) | RTT (ms) |
    | ------------------------- | -------------- | -------- |
    | `t2.small` - `t2.small`   |     1003       |  0.492   |
    | `m5.large` - `m5.large`   |     4970       |  0.203   |
    | `c5d.large` - `c5d.large` |     9520       |  0.099   |
    | `t2.small` - `c5d.large`  |     1003       |  0.484   |
    | `m5.large` - `c5d.large`  |     4960       |  0.292   |
    | `m5.large` - `t2.small`   |     1003       |  0.317   |

    > Region: US East (N. Virginia). Use `Ubuntu Server 22.04 LTS (HVM)` as AMI.

2. (1 mark) What about the network performance for instances deployed in different regions? In order to answer this question, you need to complete the following table.

    | Connection                | TCP b/w (Mbps) | RTT (ms) |
    | ------------------------- | -------------- | -------- |
    | N. Virginia - Oregon      |      25.2          |   63.5       |
    | N. Virginia - N. Virginia |      9520          |   0.099       |
    | Oregon - Oregon           |      4960          |   0.138    |
 
    > Region: US East (N. Virginia), US West (Oregon). Use `Ubuntu Server 22.04 LTS (HVM)` as AMI. All instances are `c5d.large`.
