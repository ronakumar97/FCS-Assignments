import hashlib
import datetime
import os
	
# This method would generate hashvalue for a particular time
def generateHash(system_time):
	time = system_time.encode('ASCII')
	hash_object = hashlib.sha256(time)
	hex_dig = hash_object.hexdigest()
	file = open('hash_file.txt', 'w')
	file.write(hex_dig)
	file.close()
	return hex_dig

# This method generates the OTP for a particular hashvalue
def generateOTP(input_hash):
	otp = ""
	values = []
	# Print only for verifying 
	# print 'Input Hash ' + input_hash
	values.append(input_hash[15]);
	values.append(input_hash[31]);
	values.append(input_hash[47]);
	values.append(input_hash[63]);
	for i in range(0, len(values)):
		if(values[i].isdigit()):
			otp = otp + values[i]
		elif(values[i].isalpha()):
			otp = otp + str(ord(values[i]) - 97)
	return otp

#This method is the same as above except it doesn't print the input hash
def verifyOTP(input_hash):
	otp = ""
	values = []
	values.append(input_hash[15]);
	values.append(input_hash[31]);
	values.append(input_hash[47]);
	values.append(input_hash[63]);
	for i in range(0, len(values)):
		if(values[i].isdigit()):
			otp = otp + values[i]
		elif(values[i].isalpha()):
			otp = otp + str(ord(values[i]) - 97)
	return otp

# It concatenates the date and time in the form of a string by removing certain characters
def generateTime(time):
	current = ""
	for i in range(0, len(time)):
		if(time[i] == '-' or time[i] == '.' or time[i] == ':' or time[i] == ' '):
			continue
		else:
			current = current + str(time[i])			
	return current

# Main method
def main():
	present_time = datetime.datetime.now()
	system_time = generateTime(str(present_time))
	system_time_hash = generateHash(system_time)
	output_otp = generateOTP(system_time_hash)
	print 'System time OTP is ' + output_otp
	print 'Do you want to verify ? Press 1 then'
	choice = input()
	while(choice == 1):
		print 'Enter the input hash'
		input_hash = raw_input()
		print 'Enter the OTP you want to verify'
		input_otp = raw_input()
		res_otp = verifyOTP(input_hash)
		if res_otp == input_otp:
			print 'Successfull'
			os.system("rm -rf hash_file.txt")
			break
		else:
			print 'Unsuccessfull'
		print 'Do you want to verify again? Press 1 then'
		choice = input()

if __name__ == '__main__':
	main()