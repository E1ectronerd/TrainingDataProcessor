//-------------------------------------------------------------------------

#pragma once
#include <string>
#include <vector>

//-------------------------------------------------------------------------

namespace CSVdata
{
    class CSVDataReader
    {
    public:
        
        enum Coins
        {
            ETH,
            BTC,
            BCH,
            LTC,
            BSV,
            XMR,
            NumCoins
        };
        
        struct CSVdata
        {
            double AskPrice;
            double BidPrice;
            double LastPrice;
            double MeanPrice;
            double SD;
            double Variance;
            double minPrice;
            double maxPrice;
            double priceDelta;
            double FutureAskingPrice;
            double FutureBidPrice;
        };
        
        enum DataIndex 
        {
            ETH_Ask,
            ETH_Bid,
            ETH_Last,
            BTC_Ask,
            BTC_Bid,
            BTC_Last,
            BCH_Ask,
            BCH_Bid,
            BCH_Last,
            LTC_Ask,
            LTC_Bid,
            LTC_Last,
            BSV_Ask,
            BSV_Bid,
            BSV_Last,
            XMR_Ask,
            XMR_Bid,
            XMR_Last,
            InputDataSize
        };
        struct DataIn 
        {
            double ETH_Ask;
            double ETH_Bid;
            double ETH_Last;
            double BTC_Ask;
            double BTC_Bid;
            double BTC_Last;
            double BCH_Ask;
            double BCH_Bid;
            double BCH_Last;
            double LTC_Ask;
            double LTC_Bid;
            double LTC_Last;
            double BSV_Ask;
            double BSV_Bid;
            double BSV_Last;
            double XMR_Ask;
            double XMR_Bid;
            double XMR_Last;
            
            DataIn()
            {
                ETH_Ask = 0;
                ETH_Bid = 0;
                ETH_Last = 0;
                BTC_Ask = 0;
                BTC_Bid = 0;
                BTC_Last = 0;
                BCH_Ask = 0;
                BCH_Bid = 0;
                BCH_Last = 0;
                LTC_Ask = 0;
                LTC_Bid = 0;
                LTC_Last = 0;
                BSV_Ask = 0;
                BSV_Bid = 0;
                BSV_Last = 0;
                XMR_Ask = 0;
                XMR_Bid = 0;
                XMR_Last = 0;
            }
        };
        
        CSVDataReader(std::string const& filePath, std::string const& fileName);

        bool RunProgram();
        
    private:
        
        void CalcStats(std::vector<DataIn> input);
        std::vector<double> CalcCoinStats(std::vector<double> inputPrice, Coins coin);
        void CalcSD(Coins coin);
        void WriteNNdata( std::vector<double> data, std::ofstream &fout);

    private:
        std::vector<double> m_meanPrice;
        std::vector<double> m_minPrice;
        std::vector<double> m_maxPrice;
        std::vector<double> m_SD; 
        std::vector<double> m_variance;
        std::vector<std::vector<double>> m_MeanStore;
        std::vector<double> m_MeanStoreCntr;
        std::vector<std::vector<double>> m_PastPrices;
        std::vector<double> m_PastPricesCntr; 
        
        std::string m_fileName;
        std::string m_filePath;
    };
}
