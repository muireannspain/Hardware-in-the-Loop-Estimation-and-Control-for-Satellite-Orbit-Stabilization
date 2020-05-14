/*******************************************************************************
* File Name: StepperStart_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "StepperStart.h"

/* Check for removal by optimization */
#if !defined(StepperStart_Sync_ctrl_reg__REMOVED)

static StepperStart_BACKUP_STRUCT  StepperStart_backup = {0u};

    
/*******************************************************************************
* Function Name: StepperStart_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void StepperStart_SaveConfig(void) 
{
    StepperStart_backup.controlState = StepperStart_Control;
}


/*******************************************************************************
* Function Name: StepperStart_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void StepperStart_RestoreConfig(void) 
{
     StepperStart_Control = StepperStart_backup.controlState;
}


/*******************************************************************************
* Function Name: StepperStart_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void StepperStart_Sleep(void) 
{
    StepperStart_SaveConfig();
}


/*******************************************************************************
* Function Name: StepperStart_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void StepperStart_Wakeup(void)  
{
    StepperStart_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
