#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIPv4Block(const string &s)
    {
        if (s.empty() || (s.size() > 1 && s[0] == '0'))
            return false;
        if (s.size() > 3)
            return false;
        for (char c : s)
            if (!isdigit(c))
                return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }

    bool isIPv6Block(const string &s)
    {
        if (s.empty() || s.size() > 4)
            return false;
        for (char c : s)
        {
            if (!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
                return false;
        }
        return true;
    }

    string validIPAddress(string queryIP)
    {
        // IPv4 check
        if (queryIP.find('.') != string::npos)
        {
            vector<string> parts;
            string tmp;
            stringstream ss(queryIP);
            while (getline(ss, tmp, '.'))
                parts.push_back(tmp);

            if (parts.size() != 4)
                return "Neither";
            for (auto &block : parts)
            {
                if (!isIPv4Block(block))
                    return "Neither";
            }
            return "IPv4";
        }

        // IPv6 check
        if (queryIP.find(':') != string::npos)
        {
            vector<string> parts;
            string tmp;
            stringstream ss(queryIP);
            while (getline(ss, tmp, ':'))
                parts.push_back(tmp);

            if (parts.size() != 8)
                return "Neither";
            for (auto &block : parts)
            {
                if (!isIPv6Block(block))
                    return "Neither";
            }
            return "IPv6";
        }

        return "Neither";
    }
};
