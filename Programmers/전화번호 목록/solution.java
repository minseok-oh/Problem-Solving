import java.util.Set;
import java.util.HashSet;

class Solution {
    private boolean checkPrefix(String phone, Set<String> phones) {
        String prefix = "";
        boolean ok = true;
        
        for (int i = 0; i < phone.length() - 1; i++) {
            prefix += phone.charAt(i);
            if (phones.contains(prefix)) ok = false;
        }
        return ok;
    }
    
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Set<String> phones = new HashSet<String>();
        for (String phone: phone_book) phones.add(phone);
        
        for (String phone: phone_book) {
            answer &= checkPrefix(phone, phones);
        }
        return answer;
    }
}