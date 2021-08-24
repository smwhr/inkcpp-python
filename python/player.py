import inkpython
import textwrap
import sys
import os 

def print_paragraphs(text):
	return "\n".join([textwrap.fill(p) for p in text.splitlines()])

class InkPythonPlayer:

	def __init__(self, filename):
		self.story = inkpython.Story(filename)

	def play(self):		

		while(1):
			tag_index = 0
			while(self.story.can_continue()):

				print(print_paragraphs(self.story.getline()), end = '')

				if(self.story.has_tags()):
					for t in self.story.tags()[tag_index:]:
						print("\t#%s" % t)
						tag_index+=1
				print()

			if(self.story.has_choices()):
				for c in self.story.choices():
					print("%s> %s" % (c.index(), c.text()))
				while True:
					i = input("?>")
					try:
						self.story.choose(int(i))
						break
					except:
						print("Enter a correct choice")
						continue
				continue;
			else:
				break


if __name__ == "__main__":
	bin_file = sys.argv[1] if len(sys.argv) >= 2 else (
		os.path.realpath(os.path.dirname(os.path.realpath(__file__)) + "/../ink/sample.bin")
	)
	print(bin_file)
	player = InkPythonPlayer(bin_file)
	player.play()