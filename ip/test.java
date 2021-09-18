import java.util.*;
class test{
    public static String longestPalindrome(String s) {
        int start = 0;
        int end = 0;
        if(s == null || s.length() < 1)
            return null;
        for(int i=0; i<s.length(); i++){
            int len1 = pald(s,i,i);
            int len2 = pald(s,i,i+1);
            int length = Math.max(len1, len2);
            if(length > end-start){
                start = i-((length-1)/2);
                end = i+(length/2);
            }
        }
        return s.substring(start,end+1);
    }
    public static int pald(String s, int start, int end){
        if(s == null || start > end) return 0;
        while(start >= 0 && end < s.length() && s.charAt(start) == s.charAt(end)){
            start--;
            end++;
        }
        return end-start-1;
    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        String s=scn.nextLine();
        System.out.print(longestPalindrome(s));
        
    }
}