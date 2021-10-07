static void Main(string[] args)
{
  string inputString, reverseString = string.Empty;

  Console.Write("Enter a input: ");

  inputString = Console.ReadLine();

  if (inputString != null)
  {
    for (int i = inputString.Length - 1; i >= 0; i--)
      reverseString += inputString[i].ToString();

    if (reverseString == inputString)
      Console.WriteLine("Palindrome!");

    else
      Console.WriteLine("Not Palindrome");
  }

  Console.ReadLine();
}
