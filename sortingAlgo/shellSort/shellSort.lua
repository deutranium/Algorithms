--- Sort an array using the shell sort algorithm.
--- @param t table
--- @return table
local function shellSort(t)
    local n = #t
    local gap = math.floor(n / 2)
    while gap > 0 do
        for i = gap + 1, n do
            local item = t[i]
            local j = i - gap
            while j > 0 and t[j] > item do
                t[j + gap] = t[j]
                j = j - gap
            end
            t[j + gap] = item
        end
        gap = math.floor(gap / 2)
    end
    return t
end

return shellSort