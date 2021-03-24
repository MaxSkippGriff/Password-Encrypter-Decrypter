## Password-Encrypter-Decrypter

This is a very basic password encryption/decryption program.

It uses an XOR cipher to encrypt the password data.

### XOR cipher

The cipher works in the following way. First a random key is generated. Then, XOR is done using that key to create
an encrypted output. To decrypt this output, the XOR operation is run again, that is, you only write a 1 if the
bits are exclusively different, for e.g.,

   1 0 0 1
   0 1 0 1
   
   1 1 0 0


### What to expect

This is very basic, and requires refinement.

First, you'll be prompted to enter your name and password. Then you'll be shown the name, key and the encryption output
of your password. This data is stored in the file "oldPass.txt". I have included a delete function to delete passwords
after they've been used.

Continue this process and try out different passwords.

NB:- Please don't use special characters - the password decryption only decodes upper/lowercase letters and numbers.
