/*
    Design algorithm to encode/decode: list of strings <-> string

    Encode/decode w/ non-ASCII delimiter: {len of str, "#", str}

    Time: O(n)
    Space: O(1)
*/

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            //encodes the string while adding the size of the string in front and a delimeter char
            result += to_string(str.size()) + "#" + str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            //gets the length of the string because i is the start of the number and j-1 is the char before the #
            int length = stoi(s.substr(i, j - i));
            //creates a string from j+1 which is the first letter after the # until the length
            string str = s.substr(j + 1, length);
            result.push_back(str);
            //updates i to be the first char after the recently added string
            i = j + 1 + length;
        }

        return result;
    }
};