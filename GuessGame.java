/*  Develop a Java application that plays a "guess the number" game as described below. 
a) The user interface is displayed and the user clicks the “Start Game” button to begin the game. 

b) Your application then gets a random number in the range 1-1000 inclusive (you might want to use Math.random or the Random 
class). 

c) The application then displays the following prompt (probably via a JLabel): I have a number between 1 and 1000 can you 
guess my number? Please enter a number for your first guess and then hit Enter. Post a textbox for the user to enter a number 
and post a message telling the user to hit 'Enter' after entering a guess in a textbox (probably using a JTextField). 

d) Input the user's guess in the code for a previously-registered event-handler method (consider using the event-handling 
approach discussed in the text, or the actionPerformed method of class based on the ActionListener interface, which will 
require some additional research outside the text). 

e) For the first guess color the entire background red, meaning that they are getting warmer (you might want to use the 
setBackground method for a container). If this is the second or later guess, and they are further from the correct number 
than the last guess, then color the entire background blue. If they get the correct number then color the background some 
other color than red or blue. 

f) If the user guessed the number correctly, respond with their number, post a congratulatory message, get a new random 
number, and display a JButton to start a new game. Otherwise, to help the user close in on the correct number, post a message, 
with their guessed number, whether they are "TOO HIGH" or "TOO LOW" from the correct number, and whether they are "WARMER" or 
"COLDER" (this should match the background color). Also report the guess number of the next guess (e.g. "Enter guess number 
nnn"). You might want to use a concatenated string in JLabel for these incorrect guess messages. 

g) The process is repeated each game until the user guesses the correct number. Be sure that you erase obsolete status messages. 
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class GuessGame extends JFrame {

   private static final long serialVersionUID = 1L;
   public static Object prompt1;
   private JTextField userInput;
   private JLabel comment = new JLabel(" ");
   private JLabel comment2 = new JLabel(" ");
   private int randomNumber;
   private int counter = 0;
   
public GuessGame() {
   super ("Guessing Game");
   setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   
   setLayout(new FlowLayout());
   Container c = getContentPane();
   
   JButton guessButton = new JButton("Try the number");
   JButton newGameButton = new JButton("New Game");
   JButton quitButton = new JButton("Quit");
   JLabel prompt1 = new JLabel("I have a number between 1 and 1000.");
   JLabel prompt2 = new JLabel("Can you guess the number?");
   JLabel prompt3 = new JLabel("Please enter your guess: ");
   comment = new JLabel(" ");
   comment2 = new JLabel(" ");
   userInput = new JTextField(5);
   
   c.add(prompt1);
   c.add(prompt2);
   c.add(prompt3);
   c.add(userInput);   
   c.add(guessButton);
   c.add(newGameButton);   
   c.add(comment);
   c.add(comment2);
   
   guessButton.setMnemonic('T');
   newGameButton.setMnemonic('N');
   quitButton.setMnemonic('Q');
   
   setSize(300,200);
   setLocationRelativeTo(null);
   setVisible(true);
   setResizable(false);
   
   initializeNumber();
   
   GuessButtonHandler ghandler = new GuessButtonHandler();
   guessButton.addActionListener(ghandler);
   
   NewButtonHandler nhandler = new NewButtonHandler();
   newGameButton.addActionListener(nhandler);
   
   QuitButtonHandler qhandler = new QuitButtonHandler();
   quitButton.addActionListener(qhandler);
   }
   
   private void initializeNumber() {
      randomNumber = new Random().nextInt(1000) + 1;   
   }
   
   private class GuessButtonHandler implements ActionListener {
      public void actionPerformed(ActionEvent e) {
      
         int getUserInput;
         int diff;
         int Difference;
         
         try {
            getUserInput = Integer.parseInt(userInput.getText().trim());
            counter++;
            
            if (getUserInput == randomNumber) {
               JOptionPane.showMessageDialog(null, "Correct! It took you " + counter + " guesses", "Random Number: " + randomNumber, JOptionPane.INFORMATION_MESSAGE);
               initializeNumber();
               return;
            }
            
            if (getUserInput > randomNumber) {
               comment2.setText("The guess was too HIGH. Try a lower number.");
               comment2.setForeground(Color.WHITE);
               diff = getUserInput - randomNumber;
               Difference = Math.abs(diff);
            } 
            
            else {
               comment2.setText("The guess was too LOW. Try a higher number.");
               comment2.setForeground(Color.WHITE);
               diff = randomNumber - getUserInput;
               Difference = Math.abs(diff);
            }
            
            if (Difference >= 30) {
               comment.setText("You are Cold. ");
               comment.setForeground(Color.WHITE);
               GuessGame.this.setBackgroundColor(Color.BLUE);
            }
            
            if (Difference <= 15) {
               comment.setText("You are getting Warm");
               comment.setForeground(Color.WHITE);
               GuessGame.this.setBackgroundColor(Color.RED);
            }
         }
         
         catch (NumberFormatException ex) {
            comment.setText("Enter a VALID number!");
         }
      }
   }
   
   private class NewButtonHandler implements ActionListener {
      public void actionPerformed (ActionEvent e) {
         GuessGame app = new GuessGame();
      }
   }
   
   private class QuitButtonHandler implements ActionListener {
      public void actionPerformed (ActionEvent e) {
         System.exit(0);
      }
   }
   
   private void setBackgroundColor(Color RED) {
      getContentPane().setBackground(RED);
   }
   
   public static void main(String [] args) {
     GuessGame app = new GuessGame();
   }
}

