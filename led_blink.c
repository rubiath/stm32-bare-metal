//LED Port A Pin 5
#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB1PERIPH_BASE 	(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIO_A_OFFSET 		(0x0000UL)
#define GPIO_A_BASE 		(AHB1PERIPH_BASE + GPIO_A_OFFSET)
#define RCC_OFFSET 			(0x3800UL)
#define RCC_BASE 			(AHB1PERIPH_BASE + RCC_OFFSET)
#define RCC_AHB1ENR_OFFSET	(0x30UL)
#define RCC_AHB1ENR			(*(volatile unsigned int *)(RCC_BASE + RCC_AHB1ENR_OFFSET))
#define GPIO_A_EN			(1UL<<0)
#define GPIO_MODER_OFFSET	(0x0UL)
#define GPIO_A_MODER		(*(volatile unsigned int *)(GPIO_A_BASE + GPIO_MODER_OFFSET))
/*    (1UL<<10) - SET BIT 10 to 1
 * &=~(1UL<11) - SET BIT 11 to 0 */
#define ODR_OFFSET			(0x14UL)
#define GPIO_A_ODR			(*(volatile unsigned int *)(GPIO_A_BASE + ODR_OFFSET))
#define PIN_5				(1UL<<5)
#define LED_PIN				PIN_5


int main()
{
	//Enable Clock access to GPIOA
	RCC_AHB1ENR	|= GPIO_A_EN;
	//SET PA5 as output pin
	GPIO_A_MODER |=  (1UL<<10);
	GPIO_A_MODER &=~ (1UL<<11);
	//use loop to toggle the pin
	while(1){
		GPIO_A_ODR ^= LED_PIN;
		for(int i=0;i<1000000;i++){}

	}
}


