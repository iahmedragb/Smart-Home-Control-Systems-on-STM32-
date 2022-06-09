
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

	typedef struct
	{
			volatile u32  CR1		 ;								// Config {(UN_DIR OR BI_DIR , (CRC :for check) , (DFF : data size (8,16) , (SSM : SS MODE By hardware or software ), (SSI : value of ss by software) ,  (data order) , (EN),(Boud rate ) , ( MASTER OR SLAVE ),  CPOL , CPHA }
			volatile u32  CR2		 ;
			volatile u32  SR		 ;
			volatile u32  DR		 ;								// Data 
			volatile u32  CRCPR		 ;
			volatile u32  RXCRCR	 ;
			volatile u32  TXCRCR	 ;	
			volatile u32  I2SCFGR	 ;
			volatile u32  I2SPR		 ;

		}MSPI1_t;
	
	
	#define MSPI1		((MSPI1_t *)0x40003800) 		 //	With out dereferace



#endif //SPI_PRIVATE_H
