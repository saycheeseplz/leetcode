
class AuthenticationManager {
private:
  unordered_map<string, int> mp;
  int timeline;

public:
  AuthenticationManager(int timeToLive) { this->timeline = timeToLive; }

  void generate(string tokenId, int currentTime) {
    mp[tokenId] = currentTime + timeline;
  }

  void renew(string tokenId, int currentTime) {
    if (mp[tokenId] >= currentTime) {
      mp[tokenId] += currentTime;
    }
  }

  int countUnexpiredTokens(int currentTime) {
    int count = 0;
    for (auto it : mp) {
      if (it.second >= currentTime) {
        count++;
      }
    }
    return count;
  }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
