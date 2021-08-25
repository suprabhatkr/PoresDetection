pores_output_act=[] 
for k in range(120):
  pores_output_act.append([])
  output_file=open('pores_image/pos_image'+str(k//4+1)+'/img'+str(k%4+1)+'.txt','r') 
  for line in output_file:
    pores_output_act[-1].append([])
    #print(len(line.split())) 
    for each_sym in line.split():
      pores_output_act[-1][-1].append(int(each_sym)) 
path='bin_image/bin_image'
pores_output=[] 
for k in range(1,31):
    for l in range(1,6):
        # img=Image.open(path+'sub'+str(k)+'/'+str(k)+str(l)+'.jpg')
        # img=np.array(img)
        img=[] 
        f=open(path+str(k)+str(l)+'.txt') 
        for line in f:
            img.append(line.split()) 
        pores_output.append([]) 
        for i in range(0,200):
            pores_output[-1].append([])
            for j in range(200):
                if (i==0 or j==0 or i==199 or j==199):
                    pores_output[-1][-1].append(0)
                else:
                    pores_output[-1][-1].append(0) 
                    if int(img[i][j])>=255 and int(img[i+1][j])<255 and int(img[i-1][j])<255 and int(img[i][j+1])<255:
                        pores_output[-1][-1][-1]=1
match_rate=0
for k in range(120):
    for i in range(198):
        for j in range(198):
            match_rate+=(pores_output[k][i][j] ^ pores_output_act[k][i][j]) 
match_rate=match_rate/120
print("pores_match=",(198*198-match_rate)/(198*198))