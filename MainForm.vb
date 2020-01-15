Imports System.Speech
Imports System.Speech.Synthesis

Public Class MainForm
    Dim Speaker As New SpeechSynthesizer
    Const HOURLY_RATE = 12.0

    Private Sub MainForm_Load(sender As Object, e As EventArgs) Handles MyBase.FormClosing
        Speaker.Dispose()
    End Sub
    Private Sub calculateButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles calculateButton.Click
        Speaker.SpeakAsync(amountDueLabel.Text)
        Dim hours As Double
        Dim amount As Double
        Dim isConverted As Boolean
        isConverted = Double.TryParse(hoursTextBox.Text, hours)
        If isConverted Then
            amount = hours * HOURLY_RATE
        End If
        amountDueLabel.Text = Format(amount, "Currency")
    End Sub
    Private Sub clearButton_Click(sender As Object, e As EventArgs) Handles clearButton.Click
        lastNameTextBox.Text = ""
        firstNameTextBox.Text = ""
        hoursTextBox.Text = ""
        amountDueLabel.Text = ""
    End Sub
    Private Sub exitButton_Click(sender As Object, e As EventArgs) Handles exitButton.Click
        Speaker.SpeakAsyncCancelAll()
        Me.Close()
    End Sub

    Private Sub amountDueLabel_Click(sender As Object, e As EventArgs) Handles amountDueLabel.Click
    End Sub

End Class
