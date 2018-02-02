import random
words=['chichen','dog','cat','mouse','fog']
lives_remaining = 14
guessed_letters = ''

def pick_a_word():
	return(random.choice(words))

def get_guess(word):
	print_word_with_blanks(word)
	print('Lives Remaining:'+ str(lives_remaining))
	guess=input('Guess a letter or whole word?')
	return guess

def process_guess(guess,word):
	global lives_remaining
	global guessed_letters
	lives_remaining = lives_remaining -1
	guessed_letters = guessed_letters + guess
	return False

def play():
	global lives_remaining
	word = pick_a_word()
	while(True):
		guess=get_guess(word)
		if process_guess(guess,word):
			print('You win! Well done!')
			break
		if lives_remaining == 0:
			print('You are Hung!')
			print('The word was:'+ word)
			break
		
def print_word_with_blanks(word):
	display_word=''
	for letter in word:
		if guessed_letters.find(letter) > -1:
			#letter found
			display_word=display_word+letter
		else:
			#letter_not_found
			display_word= display_word + '-'
	print (display_word)

play()


