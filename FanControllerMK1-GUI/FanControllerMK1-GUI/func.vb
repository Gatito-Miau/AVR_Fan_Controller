Imports System.Runtime.InteropServices
Module func
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure FC_Config_t
        Public sss As Integer


    End Structure


    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi)> _
    Public Structure IndexTransaction
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=260)> _
        Public MsgDirPath As String
        Public dwMsgTime As Integer
        Public dwMsgSize As Integer
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=256)> _
        Public MsgEntryId As String
        '--- You can guess the rest
        '...
    End Structure

End Module
'
'volatile int16_t			ADC_OFF					= -10;
'
'volatile uint8_t			CHANNEL_SRC		[2]		= {0,0};
'volatile uint8_t			SAMPLE_RATE				= 60;		
'
'volatile uint8_t			START_UP_DELAY			= 25;
'
'volatile uint8_t			PWM_SMOOTH_TYPE	[2]		= {0,0}; 			// 0 - normal, 1 - stretch
'volatile float				PWM_SMOOTH_LVL	[2]		= {5,5};
'volatile uint8_t			PWM_SMOOTH_AVGLV[2]		= {1,20}; 			// max = 20;
'
'volatile uint8_t			PWM_MODE		[2]		= {0,0};			// 0-Lineal 1-hyperbolic 2-logaritmic 255-custom
'volatile uint8_t			PWM_MANUAL_VALUE[2]		= {243,243};
'volatile uint8_t			PWM_MANUAL_MODE [2]		= {0,0};
'volatile uint8_t			PWM_CUSTOM		[2][16]	= {PWM_CUSTOM_INITIALIZER,PWM_CUSTOM_INITIALIZER};
'volatile uint8_t			PWM_MIN			[2]		= {27,0};			// OCR2 value
'volatile uint8_t			PWM_MAX			[2]		= {255,255};
'
'volatile float				PWM_LINEAL_ROT	[2]		= {1,1};
'volatile float				PWM_ROT_CENTER	[2]		= {127.5,127.5};
'// alineacion a multiplo de 4 obligatoria
'volatile float				HYP_A					= 1.02518438;
'volatile float				HYP_X_DIV				= 1.0;
'volatile float				HYP_X_OFF				= -15.0;
'volatile float				HYP_Y_OFF				= 26.312;
'
'volatile float				LOG_A					= 97.8648403;
'volatile float				LOG_X_DIV				= 25.5;
'volatile float				LOG_X_OFF				= -1.4509803;
'volatile float				LOG_Y_OFF				= 45.0;
