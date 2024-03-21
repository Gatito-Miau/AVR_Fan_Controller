<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.GroupBox_ChannelSelect = New System.Windows.Forms.GroupBox
        Me.RadioButton_Channel2 = New System.Windows.Forms.RadioButton
        Me.RadioButton_Channel1 = New System.Windows.Forms.RadioButton
        Me.GroupBox_GeneralSettings = New System.Windows.Forms.GroupBox
        Me.VScrollBar_ADC_OFF = New System.Windows.Forms.VScrollBar
        Me.TextBox_ADC_OFF = New System.Windows.Forms.TextBox
        Me.Label_ADC_OFF = New System.Windows.Forms.Label
        Me.GroupBox_ChannelSettings = New System.Windows.Forms.GroupBox
        Me.VScrollBar_SAMPLE_RATE = New System.Windows.Forms.VScrollBar
        Me.TextBox_SAMPLE_RATE = New System.Windows.Forms.TextBox
        Me.Label_SAMPLE_RATE = New System.Windows.Forms.Label
        Me.VScrollBar_START_UP_DELAY = New System.Windows.Forms.VScrollBar
        Me.TextBox_START_UP_DELAY = New System.Windows.Forms.TextBox
        Me.Label_START_UP_DELAY = New System.Windows.Forms.Label
        Me.GroupBox_PWMSettings = New System.Windows.Forms.GroupBox
        Me.RadioButton_SmoothNormal = New System.Windows.Forms.RadioButton
        Me.RadioButton_SmoothStretch = New System.Windows.Forms.RadioButton
        Me.Panel_SmoothType = New System.Windows.Forms.Panel
        Me.Label_SmoothType = New System.Windows.Forms.Label
        Me.Label_SmoothLVL = New System.Windows.Forms.Label
        Me.VScrollBar_SmoothLVL = New System.Windows.Forms.VScrollBar
        Me.TextBox_SmoothLVL = New System.Windows.Forms.TextBox
        Me.VScrollBar_SmoothAVG = New System.Windows.Forms.VScrollBar
        Me.TextBox_SmoothAVG = New System.Windows.Forms.TextBox
        Me.Label_SmoothAVG = New System.Windows.Forms.Label
        Me.Panel_AcelerationCurve = New System.Windows.Forms.Panel
        Me.Label_AcelerationCurve = New System.Windows.Forms.Label
        Me.RadioButton_SmoothType_Logaritmic = New System.Windows.Forms.RadioButton
        Me.RadioButton_SmoothType_Linear = New System.Windows.Forms.RadioButton
        Me.RadioButton_SmoothType_Custom = New System.Windows.Forms.RadioButton
        Me.RadioButton_SmoothType_Hyperbolic = New System.Windows.Forms.RadioButton
        Me.VScrollBar_PWMMax = New System.Windows.Forms.VScrollBar
        Me.TextBox_PWMMax = New System.Windows.Forms.TextBox
        Me.Label_PWMMax = New System.Windows.Forms.Label
        Me.VScrollBar_PWMMin = New System.Windows.Forms.VScrollBar
        Me.TextBox_PWMMin = New System.Windows.Forms.TextBox
        Me.Label_PWMMin = New System.Windows.Forms.Label
        Me.Button_SendConfig = New System.Windows.Forms.Button
        Me.ProgressBar1 = New System.Windows.Forms.ProgressBar
        Me.SplitContainer1 = New System.Windows.Forms.SplitContainer
        Me.PictureBox1 = New System.Windows.Forms.PictureBox
        Me.GroupBox_CurveParameters = New System.Windows.Forms.GroupBox
        Me.VScrollBar_Curve_A = New System.Windows.Forms.VScrollBar
        Me.TextBox_Curve_A = New System.Windows.Forms.TextBox
        Me.Label_Curve_A = New System.Windows.Forms.Label
        Me.VScrollBar_Curve_XDiv = New System.Windows.Forms.VScrollBar
        Me.TextBox_Curve_XDiv = New System.Windows.Forms.TextBox
        Me.Label_Curve_XDiv = New System.Windows.Forms.Label
        Me.VScrollBar_Curve_XOffset = New System.Windows.Forms.VScrollBar
        Me.TextBox_Curve_XOffset = New System.Windows.Forms.TextBox
        Me.Label_Curve_XOffset = New System.Windows.Forms.Label
        Me.VScrollBar_Curve_YOffset = New System.Windows.Forms.VScrollBar
        Me.TextBox_Curve_YOffset = New System.Windows.Forms.TextBox
        Me.Label_Curve_YOffset = New System.Windows.Forms.Label
        Me.CheckBox_Curve_CoarseTune = New System.Windows.Forms.CheckBox
        Me.VScrollBar1 = New System.Windows.Forms.VScrollBar
        Me.TextBox_ManualMode = New System.Windows.Forms.TextBox
        Me.CheckBox_ManualMode_AutoSet = New System.Windows.Forms.CheckBox
        Me.CheckBox_ManualMode_Enable = New System.Windows.Forms.CheckBox
        Me.GroupBox_ChannelSelect.SuspendLayout()
        Me.GroupBox_GeneralSettings.SuspendLayout()
        Me.GroupBox_ChannelSettings.SuspendLayout()
        Me.GroupBox_PWMSettings.SuspendLayout()
        Me.Panel_SmoothType.SuspendLayout()
        Me.Panel_AcelerationCurve.SuspendLayout()
        Me.SplitContainer1.Panel1.SuspendLayout()
        Me.SplitContainer1.Panel2.SuspendLayout()
        Me.SplitContainer1.SuspendLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.GroupBox_CurveParameters.SuspendLayout()
        Me.SuspendLayout()
        '
        'SerialPort1
        '
        Me.SerialPort1.BaudRate = 19200
        '
        'GroupBox_ChannelSelect
        '
        Me.GroupBox_ChannelSelect.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.GroupBox_ChannelSelect.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.GroupBox_ChannelSelect.Controls.Add(Me.RadioButton_Channel2)
        Me.GroupBox_ChannelSelect.Controls.Add(Me.RadioButton_Channel1)
        Me.GroupBox_ChannelSelect.Location = New System.Drawing.Point(411, 11)
        Me.GroupBox_ChannelSelect.Name = "GroupBox_ChannelSelect"
        Me.GroupBox_ChannelSelect.Size = New System.Drawing.Size(76, 35)
        Me.GroupBox_ChannelSelect.TabIndex = 0
        Me.GroupBox_ChannelSelect.TabStop = False
        Me.GroupBox_ChannelSelect.Text = "Channel"
        '
        'RadioButton_Channel2
        '
        Me.RadioButton_Channel2.AutoSize = True
        Me.RadioButton_Channel2.Location = New System.Drawing.Point(43, 12)
        Me.RadioButton_Channel2.Name = "RadioButton_Channel2"
        Me.RadioButton_Channel2.Size = New System.Drawing.Size(31, 17)
        Me.RadioButton_Channel2.TabIndex = 1
        Me.RadioButton_Channel2.TabStop = True
        Me.RadioButton_Channel2.Text = "2"
        Me.RadioButton_Channel2.UseVisualStyleBackColor = True
        '
        'RadioButton_Channel1
        '
        Me.RadioButton_Channel1.AutoSize = True
        Me.RadioButton_Channel1.Location = New System.Drawing.Point(6, 12)
        Me.RadioButton_Channel1.Name = "RadioButton_Channel1"
        Me.RadioButton_Channel1.Size = New System.Drawing.Size(31, 17)
        Me.RadioButton_Channel1.TabIndex = 0
        Me.RadioButton_Channel1.TabStop = True
        Me.RadioButton_Channel1.Text = "1"
        Me.RadioButton_Channel1.UseVisualStyleBackColor = True
        '
        'GroupBox_GeneralSettings
        '
        Me.GroupBox_GeneralSettings.Controls.Add(Me.VScrollBar_START_UP_DELAY)
        Me.GroupBox_GeneralSettings.Controls.Add(Me.TextBox_START_UP_DELAY)
        Me.GroupBox_GeneralSettings.Controls.Add(Me.Label_START_UP_DELAY)
        Me.GroupBox_GeneralSettings.Controls.Add(Me.VScrollBar_SAMPLE_RATE)
        Me.GroupBox_GeneralSettings.Controls.Add(Me.TextBox_SAMPLE_RATE)
        Me.GroupBox_GeneralSettings.Controls.Add(Me.Label_SAMPLE_RATE)
        Me.GroupBox_GeneralSettings.Controls.Add(Me.VScrollBar_ADC_OFF)
        Me.GroupBox_GeneralSettings.Controls.Add(Me.TextBox_ADC_OFF)
        Me.GroupBox_GeneralSettings.Controls.Add(Me.Label_ADC_OFF)
        Me.GroupBox_GeneralSettings.Location = New System.Drawing.Point(5, 0)
        Me.GroupBox_GeneralSettings.Margin = New System.Windows.Forms.Padding(1)
        Me.GroupBox_GeneralSettings.Name = "GroupBox_GeneralSettings"
        Me.GroupBox_GeneralSettings.Size = New System.Drawing.Size(493, 42)
        Me.GroupBox_GeneralSettings.TabIndex = 0
        Me.GroupBox_GeneralSettings.TabStop = False
        Me.GroupBox_GeneralSettings.Text = "General Settings"
        '
        'VScrollBar_ADC_OFF
        '
        Me.VScrollBar_ADC_OFF.Location = New System.Drawing.Point(129, 13)
        Me.VScrollBar_ADC_OFF.Name = "VScrollBar_ADC_OFF"
        Me.VScrollBar_ADC_OFF.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_ADC_OFF.TabIndex = 3
        '
        'TextBox_ADC_OFF
        '
        Me.TextBox_ADC_OFF.Location = New System.Drawing.Point(75, 13)
        Me.TextBox_ADC_OFF.Name = "TextBox_ADC_OFF"
        Me.TextBox_ADC_OFF.Size = New System.Drawing.Size(53, 20)
        Me.TextBox_ADC_OFF.TabIndex = 2
        Me.TextBox_ADC_OFF.Text = "0.00"
        Me.TextBox_ADC_OFF.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_ADC_OFF
        '
        Me.Label_ADC_OFF.AutoSize = True
        Me.Label_ADC_OFF.Location = New System.Drawing.Point(7, 16)
        Me.Label_ADC_OFF.Name = "Label_ADC_OFF"
        Me.Label_ADC_OFF.Size = New System.Drawing.Size(62, 13)
        Me.Label_ADC_OFF.TabIndex = 1
        Me.Label_ADC_OFF.Text = "Input Offset"
        Me.Label_ADC_OFF.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'GroupBox_ChannelSettings
        '
        Me.GroupBox_ChannelSettings.Controls.Add(Me.CheckBox_ManualMode_Enable)
        Me.GroupBox_ChannelSettings.Controls.Add(Me.CheckBox_ManualMode_AutoSet)
        Me.GroupBox_ChannelSettings.Controls.Add(Me.VScrollBar1)
        Me.GroupBox_ChannelSettings.Controls.Add(Me.TextBox_ManualMode)
        Me.GroupBox_ChannelSettings.Controls.Add(Me.GroupBox_CurveParameters)
        Me.GroupBox_ChannelSettings.Controls.Add(Me.PictureBox1)
        Me.GroupBox_ChannelSettings.Controls.Add(Me.GroupBox_ChannelSelect)
        Me.GroupBox_ChannelSettings.Controls.Add(Me.GroupBox_PWMSettings)
        Me.GroupBox_ChannelSettings.Location = New System.Drawing.Point(5, 46)
        Me.GroupBox_ChannelSettings.Name = "GroupBox_ChannelSettings"
        Me.GroupBox_ChannelSettings.Size = New System.Drawing.Size(493, 391)
        Me.GroupBox_ChannelSettings.TabIndex = 0
        Me.GroupBox_ChannelSettings.TabStop = False
        Me.GroupBox_ChannelSettings.Text = "Channel Settings"
        '
        'VScrollBar_SAMPLE_RATE
        '
        Me.VScrollBar_SAMPLE_RATE.Location = New System.Drawing.Point(295, 13)
        Me.VScrollBar_SAMPLE_RATE.Name = "VScrollBar_SAMPLE_RATE"
        Me.VScrollBar_SAMPLE_RATE.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_SAMPLE_RATE.TabIndex = 6
        '
        'TextBox_SAMPLE_RATE
        '
        Me.TextBox_SAMPLE_RATE.Location = New System.Drawing.Point(241, 13)
        Me.TextBox_SAMPLE_RATE.Name = "TextBox_SAMPLE_RATE"
        Me.TextBox_SAMPLE_RATE.Size = New System.Drawing.Size(53, 20)
        Me.TextBox_SAMPLE_RATE.TabIndex = 5
        Me.TextBox_SAMPLE_RATE.Text = "0.00"
        Me.TextBox_SAMPLE_RATE.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_SAMPLE_RATE
        '
        Me.Label_SAMPLE_RATE.AutoSize = True
        Me.Label_SAMPLE_RATE.Location = New System.Drawing.Point(167, 16)
        Me.Label_SAMPLE_RATE.Name = "Label_SAMPLE_RATE"
        Me.Label_SAMPLE_RATE.Size = New System.Drawing.Size(68, 13)
        Me.Label_SAMPLE_RATE.TabIndex = 4
        Me.Label_SAMPLE_RATE.Text = "Sample Rate"
        Me.Label_SAMPLE_RATE.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'VScrollBar_START_UP_DELAY
        '
        Me.VScrollBar_START_UP_DELAY.Location = New System.Drawing.Point(461, 13)
        Me.VScrollBar_START_UP_DELAY.Name = "VScrollBar_START_UP_DELAY"
        Me.VScrollBar_START_UP_DELAY.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_START_UP_DELAY.TabIndex = 9
        '
        'TextBox_START_UP_DELAY
        '
        Me.TextBox_START_UP_DELAY.Location = New System.Drawing.Point(407, 13)
        Me.TextBox_START_UP_DELAY.Name = "TextBox_START_UP_DELAY"
        Me.TextBox_START_UP_DELAY.Size = New System.Drawing.Size(53, 20)
        Me.TextBox_START_UP_DELAY.TabIndex = 8
        Me.TextBox_START_UP_DELAY.Text = "0.00"
        Me.TextBox_START_UP_DELAY.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_START_UP_DELAY
        '
        Me.Label_START_UP_DELAY.AutoSize = True
        Me.Label_START_UP_DELAY.Location = New System.Drawing.Point(328, 16)
        Me.Label_START_UP_DELAY.Name = "Label_START_UP_DELAY"
        Me.Label_START_UP_DELAY.Size = New System.Drawing.Size(73, 13)
        Me.Label_START_UP_DELAY.TabIndex = 7
        Me.Label_START_UP_DELAY.Text = "StartUp Delay"
        Me.Label_START_UP_DELAY.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'GroupBox_PWMSettings
        '
        Me.GroupBox_PWMSettings.Controls.Add(Me.VScrollBar_PWMMax)
        Me.GroupBox_PWMSettings.Controls.Add(Me.TextBox_PWMMax)
        Me.GroupBox_PWMSettings.Controls.Add(Me.Label_PWMMax)
        Me.GroupBox_PWMSettings.Controls.Add(Me.VScrollBar_PWMMin)
        Me.GroupBox_PWMSettings.Controls.Add(Me.TextBox_PWMMin)
        Me.GroupBox_PWMSettings.Controls.Add(Me.Label_PWMMin)
        Me.GroupBox_PWMSettings.Controls.Add(Me.Panel_AcelerationCurve)
        Me.GroupBox_PWMSettings.Controls.Add(Me.VScrollBar_SmoothAVG)
        Me.GroupBox_PWMSettings.Controls.Add(Me.TextBox_SmoothAVG)
        Me.GroupBox_PWMSettings.Controls.Add(Me.Label_SmoothAVG)
        Me.GroupBox_PWMSettings.Controls.Add(Me.VScrollBar_SmoothLVL)
        Me.GroupBox_PWMSettings.Controls.Add(Me.TextBox_SmoothLVL)
        Me.GroupBox_PWMSettings.Controls.Add(Me.Label_SmoothLVL)
        Me.GroupBox_PWMSettings.Controls.Add(Me.Panel_SmoothType)
        Me.GroupBox_PWMSettings.Location = New System.Drawing.Point(6, 19)
        Me.GroupBox_PWMSettings.Name = "GroupBox_PWMSettings"
        Me.GroupBox_PWMSettings.Size = New System.Drawing.Size(481, 124)
        Me.GroupBox_PWMSettings.TabIndex = 1
        Me.GroupBox_PWMSettings.TabStop = False
        '
        'RadioButton_SmoothNormal
        '
        Me.RadioButton_SmoothNormal.AutoSize = True
        Me.RadioButton_SmoothNormal.Location = New System.Drawing.Point(122, 0)
        Me.RadioButton_SmoothNormal.Name = "RadioButton_SmoothNormal"
        Me.RadioButton_SmoothNormal.Size = New System.Drawing.Size(58, 17)
        Me.RadioButton_SmoothNormal.TabIndex = 0
        Me.RadioButton_SmoothNormal.TabStop = True
        Me.RadioButton_SmoothNormal.Text = "Normal"
        Me.RadioButton_SmoothNormal.UseVisualStyleBackColor = True
        '
        'RadioButton_SmoothStretch
        '
        Me.RadioButton_SmoothStretch.AutoSize = True
        Me.RadioButton_SmoothStretch.Location = New System.Drawing.Point(266, 0)
        Me.RadioButton_SmoothStretch.Name = "RadioButton_SmoothStretch"
        Me.RadioButton_SmoothStretch.Size = New System.Drawing.Size(59, 17)
        Me.RadioButton_SmoothStretch.TabIndex = 1
        Me.RadioButton_SmoothStretch.TabStop = True
        Me.RadioButton_SmoothStretch.Text = "Stretch"
        Me.RadioButton_SmoothStretch.UseVisualStyleBackColor = True
        '
        'Panel_SmoothType
        '
        Me.Panel_SmoothType.AutoSize = True
        Me.Panel_SmoothType.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.Panel_SmoothType.Controls.Add(Me.Label_SmoothType)
        Me.Panel_SmoothType.Controls.Add(Me.RadioButton_SmoothStretch)
        Me.Panel_SmoothType.Controls.Add(Me.RadioButton_SmoothNormal)
        Me.Panel_SmoothType.Location = New System.Drawing.Point(6, 12)
        Me.Panel_SmoothType.Name = "Panel_SmoothType"
        Me.Panel_SmoothType.Size = New System.Drawing.Size(328, 20)
        Me.Panel_SmoothType.TabIndex = 2
        '
        'Label_SmoothType
        '
        Me.Label_SmoothType.AutoSize = True
        Me.Label_SmoothType.Location = New System.Drawing.Point(0, 2)
        Me.Label_SmoothType.Name = "Label_SmoothType"
        Me.Label_SmoothType.Size = New System.Drawing.Size(84, 13)
        Me.Label_SmoothType.TabIndex = 0
        Me.Label_SmoothType.Text = "Smoothing Type"
        '
        'Label_SmoothLVL
        '
        Me.Label_SmoothLVL.AutoSize = True
        Me.Label_SmoothLVL.Location = New System.Drawing.Point(6, 41)
        Me.Label_SmoothLVL.Name = "Label_SmoothLVL"
        Me.Label_SmoothLVL.Size = New System.Drawing.Size(72, 13)
        Me.Label_SmoothLVL.TabIndex = 3
        Me.Label_SmoothLVL.Text = "Smooth Level"
        '
        'VScrollBar_SmoothLVL
        '
        Me.VScrollBar_SmoothLVL.Location = New System.Drawing.Point(215, 38)
        Me.VScrollBar_SmoothLVL.Name = "VScrollBar_SmoothLVL"
        Me.VScrollBar_SmoothLVL.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_SmoothLVL.TabIndex = 5
        '
        'TextBox_SmoothLVL
        '
        Me.TextBox_SmoothLVL.Location = New System.Drawing.Point(84, 38)
        Me.TextBox_SmoothLVL.Name = "TextBox_SmoothLVL"
        Me.TextBox_SmoothLVL.Size = New System.Drawing.Size(130, 20)
        Me.TextBox_SmoothLVL.TabIndex = 4
        Me.TextBox_SmoothLVL.Text = "0.00"
        Me.TextBox_SmoothLVL.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'VScrollBar_SmoothAVG
        '
        Me.VScrollBar_SmoothAVG.Location = New System.Drawing.Point(458, 38)
        Me.VScrollBar_SmoothAVG.Name = "VScrollBar_SmoothAVG"
        Me.VScrollBar_SmoothAVG.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_SmoothAVG.TabIndex = 8
        '
        'TextBox_SmoothAVG
        '
        Me.TextBox_SmoothAVG.Location = New System.Drawing.Point(327, 38)
        Me.TextBox_SmoothAVG.Name = "TextBox_SmoothAVG"
        Me.TextBox_SmoothAVG.Size = New System.Drawing.Size(130, 20)
        Me.TextBox_SmoothAVG.TabIndex = 7
        Me.TextBox_SmoothAVG.Text = "0.00"
        Me.TextBox_SmoothAVG.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_SmoothAVG
        '
        Me.Label_SmoothAVG.AutoSize = True
        Me.Label_SmoothAVG.Location = New System.Drawing.Point(256, 41)
        Me.Label_SmoothAVG.Name = "Label_SmoothAVG"
        Me.Label_SmoothAVG.Size = New System.Drawing.Size(68, 13)
        Me.Label_SmoothAVG.TabIndex = 6
        Me.Label_SmoothAVG.Text = "Smooth AVG"
        '
        'Panel_AcelerationCurve
        '
        Me.Panel_AcelerationCurve.AutoSize = True
        Me.Panel_AcelerationCurve.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.Panel_AcelerationCurve.Controls.Add(Me.RadioButton_SmoothType_Hyperbolic)
        Me.Panel_AcelerationCurve.Controls.Add(Me.RadioButton_SmoothType_Custom)
        Me.Panel_AcelerationCurve.Controls.Add(Me.Label_AcelerationCurve)
        Me.Panel_AcelerationCurve.Controls.Add(Me.RadioButton_SmoothType_Logaritmic)
        Me.Panel_AcelerationCurve.Controls.Add(Me.RadioButton_SmoothType_Linear)
        Me.Panel_AcelerationCurve.Location = New System.Drawing.Point(6, 64)
        Me.Panel_AcelerationCurve.Name = "Panel_AcelerationCurve"
        Me.Panel_AcelerationCurve.Size = New System.Drawing.Size(465, 20)
        Me.Panel_AcelerationCurve.TabIndex = 9
        '
        'Label_AcelerationCurve
        '
        Me.Label_AcelerationCurve.AutoSize = True
        Me.Label_AcelerationCurve.Location = New System.Drawing.Point(0, 2)
        Me.Label_AcelerationCurve.Name = "Label_AcelerationCurve"
        Me.Label_AcelerationCurve.Size = New System.Drawing.Size(91, 13)
        Me.Label_AcelerationCurve.TabIndex = 0
        Me.Label_AcelerationCurve.Text = "Aceleration Curve"
        '
        'RadioButton_SmoothType_Logaritmic
        '
        Me.RadioButton_SmoothType_Logaritmic.AutoSize = True
        Me.RadioButton_SmoothType_Logaritmic.Location = New System.Drawing.Point(266, 0)
        Me.RadioButton_SmoothType_Logaritmic.Name = "RadioButton_SmoothType_Logaritmic"
        Me.RadioButton_SmoothType_Logaritmic.Size = New System.Drawing.Size(73, 17)
        Me.RadioButton_SmoothType_Logaritmic.TabIndex = 1
        Me.RadioButton_SmoothType_Logaritmic.TabStop = True
        Me.RadioButton_SmoothType_Logaritmic.Text = "Logaritmic"
        Me.RadioButton_SmoothType_Logaritmic.UseVisualStyleBackColor = True
        '
        'RadioButton_SmoothType_Linear
        '
        Me.RadioButton_SmoothType_Linear.AutoSize = True
        Me.RadioButton_SmoothType_Linear.Location = New System.Drawing.Point(122, 0)
        Me.RadioButton_SmoothType_Linear.Name = "RadioButton_SmoothType_Linear"
        Me.RadioButton_SmoothType_Linear.Size = New System.Drawing.Size(54, 17)
        Me.RadioButton_SmoothType_Linear.TabIndex = 0
        Me.RadioButton_SmoothType_Linear.TabStop = True
        Me.RadioButton_SmoothType_Linear.Text = "Linear"
        Me.RadioButton_SmoothType_Linear.UseVisualStyleBackColor = True
        '
        'RadioButton_SmoothType_Custom
        '
        Me.RadioButton_SmoothType_Custom.AutoSize = True
        Me.RadioButton_SmoothType_Custom.Location = New System.Drawing.Point(402, 0)
        Me.RadioButton_SmoothType_Custom.Name = "RadioButton_SmoothType_Custom"
        Me.RadioButton_SmoothType_Custom.Size = New System.Drawing.Size(60, 17)
        Me.RadioButton_SmoothType_Custom.TabIndex = 2
        Me.RadioButton_SmoothType_Custom.TabStop = True
        Me.RadioButton_SmoothType_Custom.Text = "Custom"
        Me.RadioButton_SmoothType_Custom.UseVisualStyleBackColor = True
        '
        'RadioButton_SmoothType_Hyperbolic
        '
        Me.RadioButton_SmoothType_Hyperbolic.AutoSize = True
        Me.RadioButton_SmoothType_Hyperbolic.Location = New System.Drawing.Point(184, 0)
        Me.RadioButton_SmoothType_Hyperbolic.Name = "RadioButton_SmoothType_Hyperbolic"
        Me.RadioButton_SmoothType_Hyperbolic.Size = New System.Drawing.Size(75, 17)
        Me.RadioButton_SmoothType_Hyperbolic.TabIndex = 3
        Me.RadioButton_SmoothType_Hyperbolic.TabStop = True
        Me.RadioButton_SmoothType_Hyperbolic.Text = "Hyperbolic"
        Me.RadioButton_SmoothType_Hyperbolic.UseVisualStyleBackColor = True
        '
        'VScrollBar_PWMMax
        '
        Me.VScrollBar_PWMMax.Location = New System.Drawing.Point(458, 90)
        Me.VScrollBar_PWMMax.Name = "VScrollBar_PWMMax"
        Me.VScrollBar_PWMMax.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_PWMMax.TabIndex = 15
        '
        'TextBox_PWMMax
        '
        Me.TextBox_PWMMax.Location = New System.Drawing.Point(327, 90)
        Me.TextBox_PWMMax.Name = "TextBox_PWMMax"
        Me.TextBox_PWMMax.Size = New System.Drawing.Size(130, 20)
        Me.TextBox_PWMMax.TabIndex = 14
        Me.TextBox_PWMMax.Text = "0.00"
        Me.TextBox_PWMMax.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_PWMMax
        '
        Me.Label_PWMMax.AutoSize = True
        Me.Label_PWMMax.Location = New System.Drawing.Point(256, 93)
        Me.Label_PWMMax.Name = "Label_PWMMax"
        Me.Label_PWMMax.Size = New System.Drawing.Size(51, 13)
        Me.Label_PWMMax.TabIndex = 13
        Me.Label_PWMMax.Text = "Maximum"
        '
        'VScrollBar_PWMMin
        '
        Me.VScrollBar_PWMMin.Location = New System.Drawing.Point(215, 90)
        Me.VScrollBar_PWMMin.Name = "VScrollBar_PWMMin"
        Me.VScrollBar_PWMMin.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_PWMMin.TabIndex = 12
        '
        'TextBox_PWMMin
        '
        Me.TextBox_PWMMin.Location = New System.Drawing.Point(84, 90)
        Me.TextBox_PWMMin.Name = "TextBox_PWMMin"
        Me.TextBox_PWMMin.Size = New System.Drawing.Size(130, 20)
        Me.TextBox_PWMMin.TabIndex = 11
        Me.TextBox_PWMMin.Text = "0.00"
        Me.TextBox_PWMMin.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_PWMMin
        '
        Me.Label_PWMMin.AutoSize = True
        Me.Label_PWMMin.Location = New System.Drawing.Point(6, 93)
        Me.Label_PWMMin.Name = "Label_PWMMin"
        Me.Label_PWMMin.Size = New System.Drawing.Size(52, 13)
        Me.Label_PWMMin.TabIndex = 10
        Me.Label_PWMMin.Text = "Minumum"
        '
        'Button_SendConfig
        '
        Me.Button_SendConfig.Dock = System.Windows.Forms.DockStyle.Fill
        Me.Button_SendConfig.Location = New System.Drawing.Point(0, 0)
        Me.Button_SendConfig.Name = "Button_SendConfig"
        Me.Button_SendConfig.Size = New System.Drawing.Size(79, 31)
        Me.Button_SendConfig.TabIndex = 0
        Me.Button_SendConfig.Text = "Send"
        Me.Button_SendConfig.UseVisualStyleBackColor = True
        '
        'ProgressBar1
        '
        Me.ProgressBar1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.ProgressBar1.Location = New System.Drawing.Point(0, 0)
        Me.ProgressBar1.Name = "ProgressBar1"
        Me.ProgressBar1.Size = New System.Drawing.Size(421, 31)
        Me.ProgressBar1.TabIndex = 2
        '
        'SplitContainer1
        '
        Me.SplitContainer1.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.SplitContainer1.Location = New System.Drawing.Point(0, 440)
        Me.SplitContainer1.Name = "SplitContainer1"
        '
        'SplitContainer1.Panel1
        '
        Me.SplitContainer1.Panel1.Controls.Add(Me.ProgressBar1)
        '
        'SplitContainer1.Panel2
        '
        Me.SplitContainer1.Panel2.Controls.Add(Me.Button_SendConfig)
        Me.SplitContainer1.Size = New System.Drawing.Size(504, 31)
        Me.SplitContainer1.SplitterDistance = 421
        Me.SplitContainer1.TabIndex = 3
        '
        'PictureBox1
        '
        Me.PictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.PictureBox1.Location = New System.Drawing.Point(256, 152)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(217, 225)
        Me.PictureBox1.TabIndex = 2
        Me.PictureBox1.TabStop = False
        '
        'GroupBox_CurveParameters
        '
        Me.GroupBox_CurveParameters.Controls.Add(Me.CheckBox_Curve_CoarseTune)
        Me.GroupBox_CurveParameters.Controls.Add(Me.VScrollBar_Curve_YOffset)
        Me.GroupBox_CurveParameters.Controls.Add(Me.TextBox_Curve_YOffset)
        Me.GroupBox_CurveParameters.Controls.Add(Me.Label_Curve_YOffset)
        Me.GroupBox_CurveParameters.Controls.Add(Me.VScrollBar_Curve_XOffset)
        Me.GroupBox_CurveParameters.Controls.Add(Me.TextBox_Curve_XOffset)
        Me.GroupBox_CurveParameters.Controls.Add(Me.Label_Curve_XOffset)
        Me.GroupBox_CurveParameters.Controls.Add(Me.VScrollBar_Curve_XDiv)
        Me.GroupBox_CurveParameters.Controls.Add(Me.TextBox_Curve_XDiv)
        Me.GroupBox_CurveParameters.Controls.Add(Me.Label_Curve_XDiv)
        Me.GroupBox_CurveParameters.Controls.Add(Me.VScrollBar_Curve_A)
        Me.GroupBox_CurveParameters.Controls.Add(Me.TextBox_Curve_A)
        Me.GroupBox_CurveParameters.Controls.Add(Me.Label_Curve_A)
        Me.GroupBox_CurveParameters.Location = New System.Drawing.Point(6, 152)
        Me.GroupBox_CurveParameters.Name = "GroupBox_CurveParameters"
        Me.GroupBox_CurveParameters.Size = New System.Drawing.Size(244, 141)
        Me.GroupBox_CurveParameters.TabIndex = 3
        Me.GroupBox_CurveParameters.TabStop = False
        '
        'VScrollBar_Curve_A
        '
        Me.VScrollBar_Curve_A.Location = New System.Drawing.Point(215, 13)
        Me.VScrollBar_Curve_A.Name = "VScrollBar_Curve_A"
        Me.VScrollBar_Curve_A.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_Curve_A.TabIndex = 15
        '
        'TextBox_Curve_A
        '
        Me.TextBox_Curve_A.Location = New System.Drawing.Point(84, 13)
        Me.TextBox_Curve_A.Name = "TextBox_Curve_A"
        Me.TextBox_Curve_A.Size = New System.Drawing.Size(130, 20)
        Me.TextBox_Curve_A.TabIndex = 14
        Me.TextBox_Curve_A.Text = "0.00"
        Me.TextBox_Curve_A.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_Curve_A
        '
        Me.Label_Curve_A.AutoSize = True
        Me.Label_Curve_A.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label_Curve_A.Location = New System.Drawing.Point(6, 16)
        Me.Label_Curve_A.Name = "Label_Curve_A"
        Me.Label_Curve_A.Size = New System.Drawing.Size(14, 13)
        Me.Label_Curve_A.TabIndex = 13
        Me.Label_Curve_A.Text = "A"
        '
        'VScrollBar_Curve_XDiv
        '
        Me.VScrollBar_Curve_XDiv.Location = New System.Drawing.Point(215, 39)
        Me.VScrollBar_Curve_XDiv.Name = "VScrollBar_Curve_XDiv"
        Me.VScrollBar_Curve_XDiv.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_Curve_XDiv.TabIndex = 18
        '
        'TextBox_Curve_XDiv
        '
        Me.TextBox_Curve_XDiv.Location = New System.Drawing.Point(84, 39)
        Me.TextBox_Curve_XDiv.Name = "TextBox_Curve_XDiv"
        Me.TextBox_Curve_XDiv.Size = New System.Drawing.Size(130, 20)
        Me.TextBox_Curve_XDiv.TabIndex = 17
        Me.TextBox_Curve_XDiv.Text = "0.00"
        Me.TextBox_Curve_XDiv.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_Curve_XDiv
        '
        Me.Label_Curve_XDiv.AutoSize = True
        Me.Label_Curve_XDiv.Location = New System.Drawing.Point(6, 42)
        Me.Label_Curve_XDiv.Name = "Label_Curve_XDiv"
        Me.Label_Curve_XDiv.Size = New System.Drawing.Size(50, 13)
        Me.Label_Curve_XDiv.TabIndex = 16
        Me.Label_Curve_XDiv.Text = "X Divider"
        '
        'VScrollBar_Curve_XOffset
        '
        Me.VScrollBar_Curve_XOffset.Location = New System.Drawing.Point(215, 65)
        Me.VScrollBar_Curve_XOffset.Name = "VScrollBar_Curve_XOffset"
        Me.VScrollBar_Curve_XOffset.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_Curve_XOffset.TabIndex = 21
        '
        'TextBox_Curve_XOffset
        '
        Me.TextBox_Curve_XOffset.Location = New System.Drawing.Point(84, 65)
        Me.TextBox_Curve_XOffset.Name = "TextBox_Curve_XOffset"
        Me.TextBox_Curve_XOffset.Size = New System.Drawing.Size(130, 20)
        Me.TextBox_Curve_XOffset.TabIndex = 20
        Me.TextBox_Curve_XOffset.Text = "0.00"
        Me.TextBox_Curve_XOffset.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_Curve_XOffset
        '
        Me.Label_Curve_XOffset.AutoSize = True
        Me.Label_Curve_XOffset.Location = New System.Drawing.Point(6, 68)
        Me.Label_Curve_XOffset.Name = "Label_Curve_XOffset"
        Me.Label_Curve_XOffset.Size = New System.Drawing.Size(45, 13)
        Me.Label_Curve_XOffset.TabIndex = 19
        Me.Label_Curve_XOffset.Text = "X Offset"
        '
        'VScrollBar_Curve_YOffset
        '
        Me.VScrollBar_Curve_YOffset.Location = New System.Drawing.Point(215, 91)
        Me.VScrollBar_Curve_YOffset.Name = "VScrollBar_Curve_YOffset"
        Me.VScrollBar_Curve_YOffset.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar_Curve_YOffset.TabIndex = 24
        '
        'TextBox_Curve_YOffset
        '
        Me.TextBox_Curve_YOffset.Location = New System.Drawing.Point(84, 91)
        Me.TextBox_Curve_YOffset.Name = "TextBox_Curve_YOffset"
        Me.TextBox_Curve_YOffset.Size = New System.Drawing.Size(130, 20)
        Me.TextBox_Curve_YOffset.TabIndex = 23
        Me.TextBox_Curve_YOffset.Text = "0.00"
        Me.TextBox_Curve_YOffset.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label_Curve_YOffset
        '
        Me.Label_Curve_YOffset.AutoSize = True
        Me.Label_Curve_YOffset.Location = New System.Drawing.Point(6, 94)
        Me.Label_Curve_YOffset.Name = "Label_Curve_YOffset"
        Me.Label_Curve_YOffset.Size = New System.Drawing.Size(45, 13)
        Me.Label_Curve_YOffset.TabIndex = 22
        Me.Label_Curve_YOffset.Text = "Y Offset"
        '
        'CheckBox_Curve_CoarseTune
        '
        Me.CheckBox_Curve_CoarseTune.AutoSize = True
        Me.CheckBox_Curve_CoarseTune.Location = New System.Drawing.Point(177, 117)
        Me.CheckBox_Curve_CoarseTune.Name = "CheckBox_Curve_CoarseTune"
        Me.CheckBox_Curve_CoarseTune.Size = New System.Drawing.Size(59, 17)
        Me.CheckBox_Curve_CoarseTune.TabIndex = 25
        Me.CheckBox_Curve_CoarseTune.Text = "Coarse"
        Me.CheckBox_Curve_CoarseTune.UseVisualStyleBackColor = True
        '
        'VScrollBar1
        '
        Me.VScrollBar1.Location = New System.Drawing.Point(159, 302)
        Me.VScrollBar1.Name = "VScrollBar1"
        Me.VScrollBar1.Size = New System.Drawing.Size(21, 20)
        Me.VScrollBar1.TabIndex = 11
        '
        'TextBox_ManualMode
        '
        Me.TextBox_ManualMode.Location = New System.Drawing.Point(90, 302)
        Me.TextBox_ManualMode.Name = "TextBox_ManualMode"
        Me.TextBox_ManualMode.Size = New System.Drawing.Size(68, 20)
        Me.TextBox_ManualMode.TabIndex = 10
        Me.TextBox_ManualMode.Text = "0.00"
        Me.TextBox_ManualMode.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'CheckBox_ManualMode_AutoSet
        '
        Me.CheckBox_ManualMode_AutoSet.AutoSize = True
        Me.CheckBox_ManualMode_AutoSet.Location = New System.Drawing.Point(183, 304)
        Me.CheckBox_ManualMode_AutoSet.Name = "CheckBox_ManualMode_AutoSet"
        Me.CheckBox_ManualMode_AutoSet.Size = New System.Drawing.Size(48, 17)
        Me.CheckBox_ManualMode_AutoSet.TabIndex = 26
        Me.CheckBox_ManualMode_AutoSet.Text = "Auto"
        Me.CheckBox_ManualMode_AutoSet.UseVisualStyleBackColor = True
        '
        'CheckBox_ManualMode_Enable
        '
        Me.CheckBox_ManualMode_Enable.AutoSize = True
        Me.CheckBox_ManualMode_Enable.Location = New System.Drawing.Point(10, 304)
        Me.CheckBox_ManualMode_Enable.Name = "CheckBox_ManualMode_Enable"
        Me.CheckBox_ManualMode_Enable.Size = New System.Drawing.Size(61, 17)
        Me.CheckBox_ManualMode_Enable.TabIndex = 27
        Me.CheckBox_ManualMode_Enable.Text = "Manual"
        Me.CheckBox_ManualMode_Enable.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.ClientSize = New System.Drawing.Size(504, 471)
        Me.Controls.Add(Me.SplitContainer1)
        Me.Controls.Add(Me.GroupBox_ChannelSettings)
        Me.Controls.Add(Me.GroupBox_GeneralSettings)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.GroupBox_ChannelSelect.ResumeLayout(False)
        Me.GroupBox_ChannelSelect.PerformLayout()
        Me.GroupBox_GeneralSettings.ResumeLayout(False)
        Me.GroupBox_GeneralSettings.PerformLayout()
        Me.GroupBox_ChannelSettings.ResumeLayout(False)
        Me.GroupBox_ChannelSettings.PerformLayout()
        Me.GroupBox_PWMSettings.ResumeLayout(False)
        Me.GroupBox_PWMSettings.PerformLayout()
        Me.Panel_SmoothType.ResumeLayout(False)
        Me.Panel_SmoothType.PerformLayout()
        Me.Panel_AcelerationCurve.ResumeLayout(False)
        Me.Panel_AcelerationCurve.PerformLayout()
        Me.SplitContainer1.Panel1.ResumeLayout(False)
        Me.SplitContainer1.Panel2.ResumeLayout(False)
        Me.SplitContainer1.ResumeLayout(False)
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.GroupBox_CurveParameters.ResumeLayout(False)
        Me.GroupBox_CurveParameters.PerformLayout()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents SerialPort1 As System.IO.Ports.SerialPort
    Friend WithEvents GroupBox_ChannelSelect As System.Windows.Forms.GroupBox
    Friend WithEvents RadioButton_Channel2 As System.Windows.Forms.RadioButton
    Friend WithEvents RadioButton_Channel1 As System.Windows.Forms.RadioButton
    Friend WithEvents GroupBox_GeneralSettings As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox_ChannelSettings As System.Windows.Forms.GroupBox
    Friend WithEvents VScrollBar_ADC_OFF As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_ADC_OFF As System.Windows.Forms.TextBox
    Friend WithEvents Label_ADC_OFF As System.Windows.Forms.Label
    Friend WithEvents VScrollBar_START_UP_DELAY As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_START_UP_DELAY As System.Windows.Forms.TextBox
    Friend WithEvents Label_START_UP_DELAY As System.Windows.Forms.Label
    Friend WithEvents VScrollBar_SAMPLE_RATE As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_SAMPLE_RATE As System.Windows.Forms.TextBox
    Friend WithEvents Label_SAMPLE_RATE As System.Windows.Forms.Label
    Friend WithEvents GroupBox_PWMSettings As System.Windows.Forms.GroupBox
    Friend WithEvents RadioButton_SmoothStretch As System.Windows.Forms.RadioButton
    Friend WithEvents RadioButton_SmoothNormal As System.Windows.Forms.RadioButton
    Friend WithEvents Panel_SmoothType As System.Windows.Forms.Panel
    Friend WithEvents Label_SmoothType As System.Windows.Forms.Label
    Friend WithEvents VScrollBar_SmoothAVG As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_SmoothAVG As System.Windows.Forms.TextBox
    Friend WithEvents Label_SmoothAVG As System.Windows.Forms.Label
    Friend WithEvents VScrollBar_SmoothLVL As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_SmoothLVL As System.Windows.Forms.TextBox
    Friend WithEvents Label_SmoothLVL As System.Windows.Forms.Label
    Friend WithEvents Panel_AcelerationCurve As System.Windows.Forms.Panel
    Friend WithEvents Label_AcelerationCurve As System.Windows.Forms.Label
    Friend WithEvents RadioButton_SmoothType_Logaritmic As System.Windows.Forms.RadioButton
    Friend WithEvents RadioButton_SmoothType_Linear As System.Windows.Forms.RadioButton
    Friend WithEvents RadioButton_SmoothType_Hyperbolic As System.Windows.Forms.RadioButton
    Friend WithEvents RadioButton_SmoothType_Custom As System.Windows.Forms.RadioButton
    Friend WithEvents VScrollBar_PWMMax As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_PWMMax As System.Windows.Forms.TextBox
    Friend WithEvents Label_PWMMax As System.Windows.Forms.Label
    Friend WithEvents VScrollBar_PWMMin As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_PWMMin As System.Windows.Forms.TextBox
    Friend WithEvents Label_PWMMin As System.Windows.Forms.Label
    Friend WithEvents Button_SendConfig As System.Windows.Forms.Button
    Friend WithEvents ProgressBar1 As System.Windows.Forms.ProgressBar
    Friend WithEvents SplitContainer1 As System.Windows.Forms.SplitContainer
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents GroupBox_CurveParameters As System.Windows.Forms.GroupBox
    Friend WithEvents CheckBox_Curve_CoarseTune As System.Windows.Forms.CheckBox
    Friend WithEvents VScrollBar_Curve_YOffset As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_Curve_YOffset As System.Windows.Forms.TextBox
    Friend WithEvents Label_Curve_YOffset As System.Windows.Forms.Label
    Friend WithEvents VScrollBar_Curve_XOffset As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_Curve_XOffset As System.Windows.Forms.TextBox
    Friend WithEvents Label_Curve_XOffset As System.Windows.Forms.Label
    Friend WithEvents VScrollBar_Curve_XDiv As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_Curve_XDiv As System.Windows.Forms.TextBox
    Friend WithEvents Label_Curve_XDiv As System.Windows.Forms.Label
    Friend WithEvents VScrollBar_Curve_A As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_Curve_A As System.Windows.Forms.TextBox
    Friend WithEvents Label_Curve_A As System.Windows.Forms.Label
    Friend WithEvents CheckBox_ManualMode_AutoSet As System.Windows.Forms.CheckBox
    Friend WithEvents VScrollBar1 As System.Windows.Forms.VScrollBar
    Friend WithEvents TextBox_ManualMode As System.Windows.Forms.TextBox
    Friend WithEvents CheckBox_ManualMode_Enable As System.Windows.Forms.CheckBox

End Class
