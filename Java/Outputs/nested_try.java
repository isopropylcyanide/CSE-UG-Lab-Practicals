
 class Second{
    static String s = "-";

    public static void main(String args[]){
        try{
            throw new Exception();
        }

        catch(Exception e){
            try{
                try{
                    throw new Exception();
                }
                catch (Exception e1){
                    s+="ab";
                }
                throw new Exception();
            }
            catch (Exception e2){
                s+= "xy";
            }
            finally{
                s+="r";
            }
        }
        
        finally{
            s+="1p";
        }
        System.out.println(s);
    }

}