import java.util.*;
class  Vigenere 
{ 
	static String generateKey(String str, String key) 
	{ 
		int x = str.length(); 
		for (int i = 0; ; i++) 
		{ 
			if (x == i) 
            i = 0; 
			if (key.length() == str.length()) 
            break; 
			key+=(key.charAt(i)); 
		} 
		return key; 
	} 
	static String cipherText(String str, String key) 
	{ 
		String cipher_text=""; 
		for (int i = 0; i < str.length(); i++) 
		{ 
			// converting in range 0-25 
			int x = (str.charAt(i) + key.charAt(i)) %26; 
			// convert into alphabets(ASCII) 
			x += 'A'; 
			cipher_text+=(char)(x); 
		} 
		return cipher_text; 
	} 
	static String originalText(String cipher_text, String key) 
	{ 
		String orig_text=""; 
		for (int i = 0 ; i < cipher_text.length() &&  i < key.length(); i++) 
		{ 
			// converting in range 0-25 
			int x = (cipher_text.charAt(i) - key.charAt(i) + 26) %26; 
			// convert into alphabets(ASCII) 
			x += 'A'; 
			orig_text+=(char)(x); 
		} 
		return orig_text; 
	} 
  
	// Driver code 
	public static void main(String[] args)  
	{ 
		String str; 
		String keyword ;
		Scanner sc=new Scanner(System.in); 
		System.out.println("enter your plaintext=");
		str=sc.nextLine();
		System.out.println("enter your key=");
		keyword=sc.nextLine();
		String key = generateKey(str, keyword); 
		String cipher_text = cipherText(str, key); 
		System.out.println("Ciphertext : "+ cipher_text + "\n"); 
		System.out.println("Original/Decrypted Text : "+ originalText(cipher_text, key)); 
    } 
} 