# Embedded Systems Developer

## About Me
My name is Saksham Srivastava, I'm an embedded systems developer with hands-on experience in STM32 microcontroller programming. I focus on bare-metal programming and building hardware drivers from scratch using C and register-level programming.

## Technical Skills

### Programming Languages
* **C** - Advanced embedded development with register-level programming
* **Assembly** - Understanding of ARM Cortex-M architecture
* **Hardware Programming** - Direct memory-mapped I/O and peripheral control

### Microcontrollers & Hardware
* **STM32F10x Series** - Extensive experience with GPIO, UART, I2C, SPI, SysTick, and interrupt systems
* **ARM Cortex-M3** - Deep understanding of architecture and peripheral programming
* **Real-time Systems** - Interrupt-driven architecture and timing-critical applications
* **Hardware Debugging** - Register-level debugging and peripheral configuration

### Communication Protocols
* **SPI (Serial Peripheral Interface)** - Master mode implementation with dual-channel support and manual chip select control
* **I2C (Inter-Integrated Circuit)** - Master mode implementation with Fast Mode (400kHz) and Standard Mode (100kHz)
* **UART/USART** - Multi-channel communication with interrupt-driven architecture
* **GPIO Management** - Advanced pin configuration and control systems
* **Multi-Protocol Integration** - Simultaneous operation of multiple communication interfaces

### Development Tools & Environments
* **STM32CubeIDE** / **Keil µVision** - Embedded development environments
* **Hardware Debugging** - Experience with debugging embedded systems
* **Protocol Analyzers** - Experience with communication protocol debugging
* **Version Control** - Code organization and project management

## Recent Projects

### Advanced SPI Communication System
**Technologies:** C, STM32F10x, SPI Protocol, Master Mode Implementation

A comprehensive SPI master implementation supporting dual SPI channels with manual chip select control:

#### **Core Features:**
* **Dual SPI Support**: Complete implementation for both SPI1 and SPI2 peripherals
* **Master Mode Operation**: Full master mode implementation with clock generation
* **Manual Chip Select**: Precise control of SS (Slave Select) signals for device selection
* **Configurable Clock Division**: Flexible clock prescaler settings (fclk/256) for different slave requirements
* **String and Character Transmission**: Support for both individual character and complete string transmission

#### **Technical Implementation:**
* **Pin Configuration**: Automatic GPIO setup for SPI pins (PA4-PA7 for SPI1, PB12-PB15 for SPI2)
* **Clock Management**: Proper APB1/APB2 clock configuration for SPI peripherals
* **Timing Control**: Precise timing using status register monitoring
* **Hardware Abstraction**: Clean API for SPI operations with automatic peripheral management

#### **Advanced Features:**
* **Chip Select Management**: Manual SS control for multi-slave communication
* **Transmission Completion Detection**: Status register monitoring for reliable data transmission
* **Flexible Data Formats**: Support for both single character and string transmission
* **Multi-Channel Operation**: Simultaneous SPI1 and SPI2 channel management

### Enhanced I2C Communication System
**Technologies:** C, STM32F10x, I2C Protocol, Multi-Speed Operation

A comprehensive I2C master implementation with dual-channel support and configurable speed modes:

#### **Key Capabilities:**
* **Dual I2C Support**: Complete implementation for both I2C1 and I2C2 peripherals
* **Multi-Speed Operation**: Support for both Fast Mode (400kHz) and Standard Mode (100kHz)
* **Robust Protocol Implementation**: Complete I2C transaction handling with proper sequencing
* **Automatic Address Handling**: 7-bit address transmission with R/W bit control

### Advanced GPIO Driver System
**Technologies:** C, STM32F10x, Hardware Abstraction Layer, Pointer Arithmetic

A sophisticated GPIO control system with dynamic register manipulation:

#### **Technical Excellence:**
* **Multi-Port Support**: Comprehensive control of GPIOA, GPIOB, and GPIOC ports
* **Dynamic Register Access**: Intelligent pointer arithmetic for CRL/CRH register selection
* **Advanced Pin Configuration**: Support for all GPIO modes including alternate function configurations
* **Atomic Operations**: Efficient pin state manipulation with bit-level control

### Multi-Protocol Communication Platform
**Technologies:** C, STM32F10x, SPI, I2C, UART, Real-time Systems

Integration of multiple communication protocols in a unified embedded system:

#### **System Architecture:**
* **Protocol Coexistence**: Simultaneous operation of SPI, I2C, and UART communication
* **Unified Timing System**: Shared SysTick timer for all communication protocols
* **Modular Design**: Separate driver modules for each communication protocol
* **Efficient Resource Management**: Optimized peripheral usage and clock configuration
* **Scalable Architecture**: Easy addition of new communication protocols

### Precision Timing System
**Technologies:** C, ARM Cortex-M3, SysTick Timer, Real-time Programming

High-precision timing system coordinating multiple communication protocols:

#### **Implementation Details:**
* **Millisecond Precision**: Accurate delay functions for timing-critical applications
* **72MHz Clock Handling**: Proper system clock configuration and timing calculations
* **Protocol Coordination**: Timing support for SPI, I2C, and UART operations
* **Scalable Delays**: Support for both single millisecond and variable duration delays

## Technical Expertise

### Communication Protocol Mastery
* **SPI Protocol**: Complete master implementation with manual chip select control
* **I2C Protocol**: Full master implementation with multi-speed support
* **UART Communication**: Multi-channel implementation with interrupt handling
* **Protocol State Machines**: Proper sequence handling for complex communication protocols
* **Multi-Protocol Coordination**: Efficient management of multiple communication interfaces

### Advanced Hardware Programming
* **Register-level Programming**: Direct manipulation of peripheral registers for optimal performance
* **Pointer Arithmetic**: Advanced memory addressing for dynamic register access
* **Bit Manipulation**: Efficient control of individual bits and bit fields
* **Clock Tree Management**: Comprehensive understanding of STM32 clock system
* **Peripheral Coordination**: Managing multiple peripherals simultaneously

### System Architecture Design
* **Hardware Abstraction Layers**: Clean separation between hardware and application layers
* **Modular Programming**: Well-structured code with clear module boundaries
* **Resource Management**: Efficient use of microcontroller resources
* **Scalable Design**: Architecture supporting easy addition of new peripherals
* **Protocol Integration**: Seamless integration of multiple communication protocols

### Real-time Programming
* **Timing Systems**: Precision timing using hardware timers
* **Status Register Management**: Efficient polling and status checking
* **State Management**: Proper handling of peripheral states and transitions
* **Performance Optimization**: Code optimization for real-time constraints

## Code Quality & Development Approach

I focus on writing production-quality embedded code with emphasis on:
* **Hardware Efficiency**: Register-level programming for maximum performance
* **Protocol Compliance**: Strict adherence to communication protocol specifications
* **Modular Architecture**: Clean separation of concerns and reusable components
* **Robust Error Handling**: Comprehensive status checking and transmission verification
* **Maintainable Code**: Clear function naming and logical code organization

## Technical Achievements

### SPI Implementation Highlights
* **Dual-Channel Master Mode**: Simultaneous SPI1 and SPI2 operation
* **Manual Chip Select Control**: Precise SS signal management for multi-slave communication
* **Configurable Clock Division**: Flexible prescaler settings for different slave requirements
* **String Transmission**: Efficient multi-byte data transmission with proper timing
* **Status Register Monitoring**: Reliable transmission completion detection

### Multi-Protocol Integration
* **Unified Driver Architecture**: Consistent API across SPI, I2C, and UART protocols
* **Resource Optimization**: Efficient sharing of GPIO and timing resources
* **Modular Design**: Independent protocol modules with clean interfaces
* **Scalable Implementation**: Easy addition of new communication protocols

### GPIO System Innovations
* **Dynamic Register Selection**: Intelligent CRL/CRH register access based on pin number
* **Pointer-Based Architecture**: Efficient memory access using calculated offsets
* **Comprehensive Pin Modes**: Support for all GPIO configurations including alternate functions
* **Atomic Pin Operations**: Thread-safe pin state manipulation

## Project Portfolio Summary

* **SPI Master System**: Dual-channel implementation with manual chip select control
* **I2C Master Implementation**: Multi-speed dual-channel system with robust protocol handling
* **Advanced GPIO Driver**: Dynamic register access with comprehensive pin control
* **Multi-UART Bridge**: Interrupt-driven communication system with real-time message routing
* **Precision Timing System**: High-accuracy timing using ARM Cortex-M3 SysTick
* **Integrated Multi-Protocol Platform**: Unified system combining SPI, I2C, and UART

## Areas of Continuous Learning

I'm actively expanding my expertise in:
* **Advanced Communication Protocols**: CAN bus, Ethernet, and USB implementation
* **Real-time Operating Systems**: FreeRTOS integration and task management
* **Power Management**: Low-power design and sleep mode optimization
* **Security Implementation**: Secure communication and data protection
* **Industry Standards**: Compliance with automotive and industrial standards

## What I'm Looking For

I'm seeking opportunities where I can:
* **Lead Multi-Protocol Development**: Utilize my SPI, I2C, and UART expertise in complex systems
* **Architect Communication Systems**: Design scalable embedded communication architectures
* **Optimize Real-time Performance**: Apply my timing and peripheral programming skills
* **Develop Integrated Solutions**: Create multi-protocol embedded communication platforms
* **Mentor Development Teams**: Share knowledge in embedded systems and protocol implementation

## Professional Strengths

* **Protocol Expertise**: Deep understanding of SPI, I2C, and UART communication protocols
* **Hardware Mastery**: Extensive experience with STM32 peripheral programming
* **System Architecture**: Ability to design scalable, maintainable embedded systems
* **Multi-Protocol Integration**: Skills in coordinating multiple communication interfaces
* **Performance Optimization**: Expertise in writing efficient, real-time embedded code
* **Problem-Solving**: Proven ability to debug complex hardware-software interactions

## Contact & Collaboration

I'm passionate about embedded systems engineering and excel at implementing complex communication protocols and multi-peripheral systems. My experience spans from low-level register programming to high-level system architecture, with particular strength in integrating multiple communication protocols in unified embedded platforms.

*I'm ready to contribute my comprehensive embedded programming skills and multi-protocol expertise to innovative projects while continuing to grow as a senior embedded systems developer.*