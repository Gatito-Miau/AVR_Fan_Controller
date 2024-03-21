Public Class Form1



    

    Private Sub TextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TextBox_ADC_OFF.TextChanged

    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Me.AutoSize = True


    End Sub



    Private Sub VScrollBar1_Scroll(ByVal sender As System.Object, ByVal e As System.Windows.Forms.ScrollEventArgs) Handles VScrollBar_ADC_OFF.Scroll
        If e.Type > 1 Or e.Type < 0 Then Return
        Select Case (e.Type)
            Case 1
                TextBox_ADC_OFF.Text -= 0.1
                Exit Select
            Case 0
                TextBox_ADC_OFF.Text += 0.1
                Exit Select
        End Select
    End Sub
End Class
