/*******************************************************************************************************************************//**
 *
 * @file		DR_NVIC.h
 * @brief		Modulo para el manejo tabla de vectores de interrupcion
 * @date		25/02/21
 * @author		Andres Yang
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include <register_types.h>
#include "DR_NVIC.h"

/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/
//registros para setear y limpiar los registros del NVIC
#define		ISER0 		( (__IO uint32_t  * ) 0xE000E100UL )
#define		ICER0 		( (__IO uint32_t  * ) 0xE000E180UL )

/***********************************************************************************************************************************
 *** FUNCIONES
 **********************************************************************************************************************************/
void NVIC_enableIRQ(IRQn_Type IRQn)
{
	ISER0[((uint32_t)(IRQn) / 32)] = (1 << ((uint32_t)(IRQn) % 32)); /* enable interruptions*/
}


void NVIC_disableIRQ(IRQn_Type IRQn)
{
	ICER0[((uint32_t)(IRQn) / 32)] = (1 << ((uint32_t)(IRQn) % 32)); /* disable interruptions*/
}

/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/
