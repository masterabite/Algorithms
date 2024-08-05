using System;
using System.Collections;

namespace C_sharp_noname
{
    internal class Program { 

        static void Main()
        {
            //запрашиваем и вводим N
            Console.Write("Введите кол-во строк: ");
            int n = Convert.ToInt32(Console.ReadLine());

            //определяем строку символов разделителей
            string separators = "()[];-,.!?:\"'{} ";

            for (int i = 0; i < n; ++i)
            {
                //массив подходящих слов
                ArrayList words = new ArrayList();

                //вводим строку
                Console.Write("\nВведите строку: ");
                string str = Console.ReadLine();
                int ind = 0;
                while (ind != str.Length)
                {
                    //в функцию передаем ind через ссылку, чтобы изменять его внутри функции
                    string word = NextWord(separators, str, ref ind);

                    //после получения очередного слова, проверяем его и добавляем в массив при необходимости
                    if (CheckWord(word))
                    {
                        words.Add(word);
                    }
                }
                Console.WriteLine("Строка: \"" + str + "\"");
                Console.WriteLine(String.Format("Кол-во слов, соответствующих условию: {0}", words.Count));

                if (words.Count == 0) { continue; }  //если список пустой, пропускаем его вывод

                Console.WriteLine("Список слов: ");
                for (int j = 0; j < words.Count; ++j) 
                {
                    Console.Write(words[j] + (j < words.Count-1? ", ": "\n"));
                }
            }
        }

        //функция находит следующее слово в строке, начиная с индекса ind, попутно сдвигая его до конца этого слова
        //считаем что разделители слов это символы, составляющие строку separators
        static string NextWord(string separators, string str, ref int ind)
        {
            string word = "";
            while (ind < str.Length && separators.IndexOf(str[ind]) != -1)
            {
                ++ind;
            }
            while (ind < str.Length && separators.IndexOf(str[ind]) == -1)
            {
                word += str[ind++];
            }
            return word;
        }

        //функция находит следующее слово в строке, начиная с индекса ind, попутно сдвигая его до конца этого слова
        //считаем что разделители слов это символы, составляющие строку separators
        static bool CheckWord(string word)
        {
            //проверка на пустую строку
            if (word == "")
            {
                return false;
            }

            word = word.ToUpper();
            for (int i = 0; i < word.Length; ++i)
            {
                for (int j = i+1; j < word.Length; ++j)
                {
                    if (word[i] == word[j])
                    {
                        return false;
                    }
                }
            }

            return true;
        }
    }
}
